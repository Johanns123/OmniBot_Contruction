#include "../include/encoders.hpp"

data motors;

void read_encoders(void)
{
    static uint8_t read1 = 0, old_read1 = 0, read2 = 0, old_read2 = 0, read3 = 0, old_read3 = 0, read4 = 0, old_read4 = 0;

    read1 = gpio_get(OUTR_A);
    read2 = gpio_get(OUTR_C);
    read3 = gpio_get(OUTL_A);
    read4 = gpio_get(OUTL_C);

    if(read1 < old_read1)
    {
        // puts("Motor D1");
        if(gpio_get(OUTR_B))
        {
            pulse_number_enc_MR1++;
        }

        else
        {
            pulse_number_enc_MR1--;
        }
    }

    else if(read2 < old_read2)
    {
        // puts("Motor D2");
        if(gpio_get(OUTR_D))
        {
            pulse_number_enc_MR2++;
        }

        else
        {
            pulse_number_enc_MR2--;
        }
    }

    else if(read3 < old_read3)
    {
        // puts("Motor E1");
        if(gpio_get(OUTL_B))
        {
            pulse_number_enc_MR3--;
        }

        else
        {
            pulse_number_enc_MR3++;
        }
    }

    else if(read4 < old_read4)
    {
        // puts("Motor E2");
        if(gpio_get(OUTL_D))
        {
            pulse_number_enc_MR4--;
        }

        else
        {
            pulse_number_enc_MR4++;
        }
    }

    old_read1 = read1;
    old_read2 = read2;
    old_read3 = read3;
    old_read4 = read4;

}

#define TS 0.05 //50ms

float get_angular_freq_motorMR1(void)
{
 
    static int16_t previous_pulse = 0;
    static float w_raw = 0;

    delta_pulse_MR1 = pulse_number_enc_MR1 - previous_pulse;

    w_raw = (2.0 * 3.141592 * delta_pulse_MR1)/(PULSES*TS); 

    previous_pulse = pulse_number_enc_MR1;
    return w_raw;
}

float get_angular_freq_motorMR2(void)
{
    static int16_t previous_pulse = 0;
    static float w_raw = 0;

    delta_pulse_MR2 = pulse_number_enc_MR2 - previous_pulse;

    w_raw = (2.0 * 3.141592 * delta_pulse_MR2)/(PULSES*TS); 

    previous_pulse = pulse_number_enc_MR2;
    return w_raw;
}

float get_angular_freq_motorMR3(void)
{
    static int16_t previous_pulse = 0;
    static float w_raw = 0;

    delta_pulse_MR3 = pulse_number_enc_MR3 - previous_pulse;

    w_raw = (2.0 * 3.141592 * delta_pulse_MR3)/(PULSES*TS); 

    previous_pulse = pulse_number_enc_MR3;
    return w_raw;
}

float get_angular_freq_motorMR4(void)
{
    static int16_t previous_pulse = 0;
    static float w_raw = 0;

    delta_pulse_MR4 = pulse_number_enc_MR4 - previous_pulse;

    w_raw = (2.0 * 3.141592 * delta_pulse_MR4)/(PULSES*TS); 

    previous_pulse = pulse_number_enc_MR4;
    return w_raw;
}

data encoders::motors_data(void)
{
    data d;
    
    w_raw_R1 = get_angular_freq_motorMR1();
    w_raw_R2 = get_angular_freq_motorMR2();
    w_raw_L1 = get_angular_freq_motorMR3();
    w_raw_L2 = get_angular_freq_motorMR4();

    d.w_MR1 = w_raw_R1;
    d.w_MR2 = w_raw_R2;
    d.w_MR3 = w_raw_L1;
    d.w_MR4 = w_raw_L2;

    d.delta_S = encoders::dist_linear();
    d.delta_theta = encoders::dist_angular();

    encoders::calc_right_angular_speed_average();
    encoders::calc_left_angular_speed_average();
    d.w = encoders::angular_speed();
    d.V = encoders::linear_speed();

    return d;
}


float encoders::linear_speed(void)
{
    return (((W_rigth_avg + W_left_avg)*RADIUS)/2);
}

float encoders::angular_speed(void)
{
    return (((W_rigth_avg - W_left_avg)*RADIUS)/LENGTH);
}

void encoders::calc_right_angular_speed_average(void)
{
    W_rigth_avg = (w_raw_R1 + w_raw_R2)/2.0;
} 

void encoders::calc_left_angular_speed_average(void)
{
    W_left_avg = (w_raw_L1 + w_raw_L2)/2.0;
}

float encoders::dist_linear(void)
{
    static float delta_pulse_right_avg = 0, delta_pulse_left_avg = 0;

    delta_pulse_right_avg = (delta_pulse_MR1+delta_pulse_MR2)/2;
    delta_pulse_left_avg = (delta_pulse_MR3+delta_pulse_MR4)/2;

    delta_s = ((delta_pulse_right_avg+delta_pulse_left_avg)*PULSE_TO_LINEAR_DIST)/2;

    return (delta_s);
}
float encoders::dist_angular(void)
{
    static float delta_pulse_right_avg = 0, delta_pulse_left_avg = 0;

    delta_pulse_right_avg = (delta_pulse_MR1+delta_pulse_MR2)/2;
    delta_pulse_left_avg = (delta_pulse_MR3+delta_pulse_MR4)/2;

    delta_theta = ((delta_pulse_right_avg-delta_pulse_left_avg)*PULSE_TO_LINEAR_DIST)/LENGTH;
    return (delta_theta);
}