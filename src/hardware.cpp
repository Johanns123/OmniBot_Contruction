#include "../include/hardware.hpp"

void gpio_config(void)
{
    uint32_t pin_mask = 
    (1 << TX0)  | (1 << OUTR_A) | (1 << MUXC)                 |
    (1 << RX0)  | (1 << OUTR_B) | (1 << MUXD)                 |
    (1 << PWMA) | (1 << OUTR_C) | (1 << BUTTON)               |
    (1 << PWMB) | (1 << OUTR_D) | (1 << AD_PIN)               |
    (1 << SDA)  | (1 << OUTL_A) | (1 << BATT)                 |
    (1 << SCL)  | (1 << OUTL_B) | (1 << PICO_DEFAULT_LED_PIN) |
    (1 << PWMC) | (1 << OUTL_C) |
    (1 << PWMD) | (1 << OUTL_D) |
    (1 << TX1)  | (1 << MUXA)   |
    (1 << RX1)  | (1 << MUXB); // Habilita os pinos do hardware

    uint32_t pin_output =
    (1 << TX0)                  |
    (1 << PWMA)                 |
    (1 << PWMB)                 |
    (1 << SCL)                  | 
    (1 << PWMC)                 |
    (1 << PWMD)                 |
    (1 << TX1)                  | 
    (1 << MUXA)                 |
    (1 << MUXB)                 |
    (1 << MUXC)                 |
    (1 << PICO_DEFAULT_LED_PIN) |
    (1 << MUXD);


    uint32_t pin_input = 
    (1 << OUTR_A) | (1 << BATT)   |
    (1 << RX0)    | (1 << OUTR_B) |
    (1 << OUTR_C) | (1 << BUTTON) |
    (1 << OUTR_D) | (1 << AD_PIN) |
    (1 << OUTL_A) | 
    (1 << OUTL_B) |
    (1 << OUTL_C) |
    (1 << OUTL_D) |
    (1 << RX1);
    
    gpio_init_mask(pin_mask);
    gpio_set_dir_in_masked(pin_input);
    gpio_set_dir_out_masked(pin_output);
}

void adc_config(void)
{
    adc_init(); //inicializa o ADC
    adc_gpio_init(AD_PIN);
    adc_gpio_init(BATT);
    adc_set_clkdiv(0);  //defino a divisao do clk para gerar 500 kHz
    adc_select_input(0); //ADC0
}

void pwm_init(void)
{
    gpio_set_function(PWMA, GPIO_FUNC_PWM);
    gpio_set_function(PWMB, GPIO_FUNC_PWM);
    gpio_set_function(PWMC, GPIO_FUNC_PWM);
    gpio_set_function(PWMD, GPIO_FUNC_PWM);

    slice_pwma = pwm_gpio_to_slice_num(PWMA);
    slice_pwmb = pwm_gpio_to_slice_num(PWMB);
    slice_pwmc = pwm_gpio_to_slice_num(PWMC);
    slice_pwmd = pwm_gpio_to_slice_num(PWMD);
    // Obtém o slice de PWM correspondente à GPIO do LED.
    float clock_div = 133e6/(PWM_RANGE * PWM_FREQ) - 1;

    pwm_set_clkdiv(slice_pwma, clock_div); //defino o clock de 2kHz
    pwm_set_wrap(slice_pwma, PWM_RANGE); //defino o TOP da resolucao desejada
    pwm_set_enabled(slice_pwma, true);    

    pwm_set_clkdiv(slice_pwmb, clock_div); //defino o clock de 2kHz
    pwm_set_wrap(slice_pwmb, PWM_RANGE); //defino o TOP da resolucao desejada
    pwm_set_enabled(slice_pwmb, true);    

    pwm_set_clkdiv(slice_pwmc, clock_div); //defino o clock de 2kHz
    pwm_set_wrap(slice_pwmc, PWM_RANGE); //defino o TOP da resolucao desejada
    pwm_set_enabled(slice_pwmc, true);    

    pwm_set_clkdiv(slice_pwmd, clock_div); //defino o clock de 2kHz
    pwm_set_wrap(slice_pwmd, PWM_RANGE); //defino o TOP da resolucao desejada
    pwm_set_enabled(slice_pwmd, true);    

}

void uart0_config(void)
{
    uart_init(UART_ID, 115200); //configurar no módulo o baud rate
    gpio_set_function(RX0, GPIO_FUNC_UART);
    gpio_set_function(TX0, GPIO_FUNC_UART);
}

void i2c_config(void)
{
    i2c_init(i2c, 400000); //400 kHz
    gpio_set_function(SDA, GPIO_FUNC_I2C); // SDA
    gpio_set_function(SCL, GPIO_FUNC_I2C); // SCL
    gpio_pull_up(SDA);
    gpio_pull_up(SCL);
}