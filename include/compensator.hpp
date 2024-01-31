#ifndef PID_H
#define PID_H

#include <stdio.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#include <math.h>
#include "encoders.hpp"

extern data Wheels;

float PID_control(float error, float kp, float ki, float kd);
uint16_t MR_F_compensator(float w_ref);
uint16_t ML_F_compensator(float w_ref);
uint16_t MR_B_compensator(float w_ref);
uint16_t ML_B_compensator(float w_ref);

#endif