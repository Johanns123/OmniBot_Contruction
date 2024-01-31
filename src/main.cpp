#include "../include/main.hpp"


/*=====================*/
int main(void)
{
    stdio_init_all();
    gpio_config();
    adc_config();
    pwm_init();
    uart0_config();
    i2c_config();
    mpu6050_config();
    extender.setup(false, false);
    extender.set_io_direction(0x0000);

    enable_external_interrupts();


    enableTimer();

    while(1) 
    {
        
    }

    return 0;
}

void enableTimer(void)
{
    // Imprime na porta serial o nome desta função, auxiliando no debug.
    puts(__func__);

    // Cria um timer repetitivo que chama a função timerCallback no intervalo especificado,
    // armazena uma referência ao timer na variável ledTimer para que possamos cancelá-lo.
    add_repeating_timer_ms(TIMER0_INTERVAL_MS, f_timers, NULL, &timer0);
}

void disableTimer(void)
{
    // Imprime na porta serial o nome desta função, auxiliando no debug.
    puts(__func__);

    // Cancela o timer, interrompendo as chamadas para o callback.
    cancel_repeating_timer(&timer0);
}

void enc_motors (uint gpio, uint32_t events)
{
    read_encoders();
}

bool f_timers(struct repeating_timer *timer)
{
    static uint16_t counter0 = 1;

    if(counter0 < 1) counter0++;

    else
    {
        //conferir periodo de amostragem do ADC
        adc_maq(); //80 ciclos de AD -> FADC = FOSC/90

        counter0 = 1;
    }

    return true;
}

void blynk_led(void)
{
    gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));
}

float voltage_measure(uint16_t AD_val)
{
    return (float)(8.4*AD_val/4096.0);  //parar robo incondicionalmente com 6.7 V
}

void enable_external_interrupts(void)
{
    // Habilita uma interrupção sempre que a GPIO do botão cair para o nível de gnd,
    // chamando a função buttonCallback.
    gpio_set_irq_enabled_with_callback(OUTR_A, GPIO_IRQ_EDGE_FALL  | GPIO_IRQ_EDGE_RISE, true, &enc_motors);
    gpio_set_irq_enabled_with_callback(OUTR_C, GPIO_IRQ_EDGE_FALL  | GPIO_IRQ_EDGE_RISE, true, &enc_motors);
    gpio_set_irq_enabled_with_callback(OUTL_A, GPIO_IRQ_EDGE_FALL  | GPIO_IRQ_EDGE_RISE, true, &enc_motors);
    gpio_set_irq_enabled_with_callback(OUTL_C, GPIO_IRQ_EDGE_FALL  | GPIO_IRQ_EDGE_RISE, true, &enc_motors);
}

void mpu6050_read(void)
{
    // Fetch all data from the sensor | I2C is only used here
    mpu6050_event(&mpu6050);

    // Pointers to float vectors with all the results
    accel = mpu6050_get_accelerometer(&mpu6050);
    gyro = mpu6050_get_gyroscope(&mpu6050);

    // Activity struct holding all interrupt flags
    activities = mpu6050_read_activities(&mpu6050);

    // Rough temperatures as float -- Keep in mind, this is not a temperature sensor!!!
    tempC = mpu6050_get_temperature_c(&mpu6050);
}

uint16_t sharp_distance(uint16_t sensor, uint8_t SENSORS)
{
    static uint16_t distance = 0;
    static float volts = 0.0;

    volts = sensor * (5.0/4096.0);

    if(!SENSORS)
    {
        /*sensor de ate 150cm*/
        // distance = 60*pow(volts, -1);
        /*forma alternativa para ler ate 150cm*/
        distance = 10650.08 * pow((sensor*1023.0/4096.0),-0.935) - 10;
        if(distance > 150)
            distance = 150;
    }

    else
    {
        /*sensor de ate 80cm*/
        // uint16_t distance = 26*pow(volts, -1);
        /*forma alternativa de medir ate 80cm*/
        distance = (6762/((sensor*1023.0/4096.0)-9))-4;
        if(distance > 80)
            distance = 80;
    }
    
    return distance;
}

void mpu6050_config(void)
{
    // Pass in the I2C driver (Important for dual-core operations). The second parameter is the address,
    // which can change if you connect pin A0 to GND or to VCC.

    // Check if the MPU6050 can initialize
    if (mpu6050_begin(&mpu6050))
    {
        // Set scale of gyroscope
        mpu6050_set_scale(&mpu6050, MPU6050_SCALE_2000DPS);
        // Set range of accelerometer
        mpu6050_set_range(&mpu6050, MPU6050_RANGE_16G);

        // Enable temperature, gyroscope and accelerometer readings
        mpu6050_set_temperature_measuring(&mpu6050, true);
        mpu6050_set_gyroscope_measuring(&mpu6050, true);
        mpu6050_set_accelerometer_measuring(&mpu6050, true);

        // Enable free fall, motion and zero motion interrupt flags
        mpu6050_set_int_free_fall(&mpu6050, false);
        mpu6050_set_int_motion(&mpu6050, false);
        mpu6050_set_int_zero_motion(&mpu6050, false);

        // Set motion detection threshold and duration
        mpu6050_set_motion_detection_threshold(&mpu6050, 2);
        mpu6050_set_motion_detection_duration(&mpu6050, 5);

        // Set zero motion detection threshold and duration
        mpu6050_set_zero_motion_detection_threshold(&mpu6050, 4);
        mpu6050_set_zero_motion_detection_duration(&mpu6050, 2);
    }
    
    else
    {
        while (1)
        {
            // Endless loop
            printf("Error! MPU6050 could not be initialized. Make sure you've entered the correct address. And double check your connections.");
            sleep_ms(500);
        }
    }
}