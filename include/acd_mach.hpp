#include "hardware.hpp"

#ifndef ADC_MACH
#define ADC_MACH

#define NUM_SENSORS 16
extern uint16_t sensors[NUM_SENSORS];

void adc_maq(void);

#endif