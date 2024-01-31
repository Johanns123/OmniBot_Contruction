#include "hardware.hpp"

#ifndef MOTORES
#define MOTORES

void move_foward(void);
void move_off(void);
void move_backward(void);
void move_right(void);
void move_left(void);
void move_foward_right(void);
void move_foward_left(void);
void move_backward_right(void);
void move_backward_left(void);
void move_turning_right(void);
void move_turning_left(void);
void move_curved(uint16_t pwm_value1, uint16_t pwm_value2, uint16_t pwm_value3, uint16_t pwm_value4);
void move_lateral_arc_R_fow(void);
void move_lateral_arc_L_fow(void);
void update_pwm(uint16_t pwm_value1, uint16_t pwm_value2, uint16_t pwm_value3, uint16_t pwm_value4);
void motors_test_move(void);

#endif