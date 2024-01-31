#include "hardware.hpp"
#include <math.h>

#ifndef ENCODER
#define ENCODER


#define PULSES  330
#define RADIUS  0.04 //40 mm em m
#define PULSE_TO_LINEAR_DIST 2*M_PI*RADIUS/PULSES //pulses/m
#define LENGTH 0.146 //146 mm em m


extern int16_t pulse_number_enc_MR1, pulse_number_enc_MR2, pulse_number_enc_MR3, pulse_number_enc_MR4;

extern int16_t delta_pulse_MR1, delta_pulse_MR2, delta_pulse_MR3, delta_pulse_MR4;

typedef struct
{
    float delta_S; 
    float delta_theta;
    float V;
    float w;
    float w_MR1;
    float w_MR2;
    float w_MR3;
    float w_MR4;
} data;


class encoders
{
    public:
        data motors_data(void);
    
    private:
        float W_rigth_avg = 0, W_left_avg =  0; 
        float w_raw_R1 = 0, w_raw_R2 = 0, w_raw_L1 = 0, w_raw_L2 = 0, delta_theta, delta_s;
        void calc_right_angular_speed_average(void);
        void calc_left_angular_speed_average(void);
        float linear_speed(void);
        float angular_speed(void);
        float dist_linear(void);
        float dist_angular(void);
};

void read_encoders(void);
float get_angular_freq_motorMR1(void);
float get_angular_freq_motorMR2(void);
float get_angular_freq_motorMR3(void);
float get_angular_freq_motorMR4(void);

#endif