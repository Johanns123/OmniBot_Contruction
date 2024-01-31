#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#include <hardware/adc.h>
#include <hardware/pwm.h>
#include <hardware/irq.h>
#include <hardware/dma.h>
#include <hardware/i2c.h>
#include <hardware/uart.h>
#include <mcp23017.h>
#include "MPU6050.h"

#ifndef HARDWARE
#define HARDWARE

#define MCP23017_I2C_ADDRESS 0x20
#define TIMER0_INTERVAL_MS 1
#define NUM_SENSORS 16

/*mapeamento de hardware*/
/*=====================*/
#define TX0     0
#define RX0     1
#define PWMA    2
#define PWMB    3
#define SDA     4
#define SCL     5
#define PWMC    6
#define PWMD    7
#define TX1     8
#define RX1     9
#define OUTR_A  10
#define OUTR_B  11
#define OUTR_C  12
#define OUTR_D  13
#define OUTL_A  14
#define OUTL_B  15
#define OUTL_C  16
#define OUTL_D  17
#define MUXA    18
#define MUXB    19
#define MUXC    20
#define MUXD    21
#define BUTTON  22
#define AD_PIN  26
#define BATT    27

#define AIN1 (0 + 8) //motor esq1 tras
#define AIN2 (1 + 8) //motor esq1 frente
#define AIN3 (2 + 8) //motor dir1 frente
#define AIN4 (3 + 8) //motor dir1 tras
#define BIN1 (4 + 8) //motor esq2 tras
#define BIN2 (5 + 8) //motor esq2 frente
#define BIN3 (6 + 8) //motor dir1 frente
#define BIN4 (7 + 8) //motor dir1 tras

#define UART_ID uart0 
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE

extern uint16_t slice_pwma, slice_pwmb, slice_pwmc, slice_pwmd;

extern const uint PWM_FREQ;  // Frequência PWM desejada (2kHz)
extern const uint PWM_RANGE;  // Resolução do PWM (12 bits)

extern i2c_inst_t *i2c;
extern Mcp23017 extender;

void gpio_config(void);
void adc_config(void);
void pwm_init(void);
void uart0_config(void);
void i2c_config(void);

#endif