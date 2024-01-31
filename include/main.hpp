/*Inclusao de bibliotecas*/
#include "motores.hpp"
#include "MPU6050.h"
#include "hardware.hpp"
#include "encoders.hpp"
#include "acd_mach.hpp"
#include "compensator.hpp"
#include <math.h>

/*enums*/
/*=====================*/
enum SENSORS
{
    FRONT, LEFT, RIGHT, BACK
};

typedef struct
{
    float x;
    float x_1;
    float y;
    float y_1;
    float theta;
    float theta_1;
} coordinate;

/*variaveis globais*/
/*=====================*/
uint16_t slice_pwma = 0, slice_pwmb = 0,
slice_pwmc = 0, slice_pwmd = 0;
const uint PWM_FREQ = 2000;  // Frequência PWM desejada (2kHz)
const uint PWM_RANGE = 4096;  // Resolução do PWM (12 bits)
uint16_t sensors[NUM_SENSORS] = {0};
float battery_value = 0;
static int addr = 0x68;
float tempC;
int16_t pulse_number_enc_MR1 = 0, pulse_number_enc_MR2 = 0, pulse_number_enc_MR3 = 0, pulse_number_enc_MR4 = 0;

uint8_t front_sensor, lateral_sensor_L, lateral_sensor_R, back_sensor;

int16_t delta_pulse_MR1 = 0, delta_pulse_MR2 = 0, delta_pulse_MR3 = 0, delta_pulse_MR4 = 0;

/*definicoes de classes*/
/*=====================*/
mpu6050_t mpu6050 = mpu6050_init(i2c_default, MPU6050_ADDRESS_A0_GND);
Mcp23017 extender(i2c, MCP23017_I2C_ADDRESS);

data Wheels;

encoders my_wheels;

coordinate global;

/*definicoes de structs*/
/*=====================*/
struct repeating_timer timer0;
mpu6050_vectorf_t *accel;
mpu6050_vectorf_t *gyro;
mpu6050_activity_t *activities;
i2c_inst_t *i2c = i2c0;

/*prototipo das funcoes*/
/*=====================*/
void enc_motors (uint gpio, uint32_t events);
bool f_timers(struct repeating_timer *timer);
void enableTimer(void);
void disableTimer(void);
void blynk_led(void);
void enable_external_interrupts(void);
void mpu6050_read(void);
float voltage_measure(uint16_t AD_val);
uint16_t sharp_distance(uint16_t sensor, uint8_t SENSORS);
void mpu6050_config(void);