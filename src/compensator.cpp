#include <../include/compensator.hpp>

float PID_control(float error, float kp, float ki, float kd)
{
    static float previous_error = 0;
    static float P = 0.0, I = 0.0, D = 0.0, PID = 0.0;
    #define TS 0.05 //50ms
    
    ki *= TS;
    kd /= TS;

    P = error;

    I += error;

    D = error - previous_error;

    PID = (kp * P) + (ki * I) + (kd * D);

    previous_error = error;

    return PID;
}


uint16_t MR_F_compensator(float w_ref)
{

    static float uk = 0, uk_1 = 0, ek = 0, ek_1 = 0, yk = 0, yk_1 = 0, PV = 0; 
    static uint16_t uk_pwm = 0;

    PV = Wheels.w_MR1;
    ek = w_ref - PV;

    /*Modelo real*/
    uk = 0.48435*ek-0.158721495*ek_1+uk_1;

    /*Modelo teorico*/
    // yk = 0.5134*yk_1 + 1.359*uk_1;
    // yk_1 = yk;

    uk_1 = uk;
    ek_1 = ek;

    uk_pwm = (uint16_t)fabs(uk*(4096.0/12.0));

    // printf("%.2f %.2f %.2f\n", w_ref, PV, yk);

    return uk_pwm;
}

uint16_t ML_F_compensator(float w_ref)
{

    static float uk = 0, uk_1 = 0, ek = 0, ek_1 = 0, yk = 0, yk_1 = 0, PV = 0; 
    static uint16_t uk_pwm = 0;

    PV = Wheels.w_MR3;
    ek = w_ref - PV;

    /*Modelo real*/
    uk = 0.59807*ek-0.197064065*ek_1+uk_1;

    /*Modelo teorico*/
    // yk = 0.5134*yk_1 + 1.39*uk_1;
    // yk_1 = yk;

    uk_1 = uk;
    ek_1 = ek;

    uk_pwm = (uint16_t)fabs(uk*(4096.0/12.0));

    return uk_pwm;
}

uint16_t MR_B_compensator(float w_ref)
{

    static float uk = 0, uk_1 = 0, ek = 0, ek_1 = 0, yk = 0, yk_1 = 0, PV = 0; 
    static uint16_t uk_pwm = 0;

    PV = Wheels.w_MR2;
    ek = w_ref - PV;

    /*Modelo real*/
    uk = 0.44963*ek-0.194150234*ek_1+uk_1;

    /*Modelo teorico*/
    // yk = 0.5134*yk_1 + 1.421*uk_1;
    // yk_1 = yk;

    uk_1 = uk;
    ek_1 = ek;

    uk_pwm = (uint16_t)fabs(uk*(4096.0/12.0));

    return uk_pwm;
}

uint16_t ML_B_compensator(float w_ref)
{

    static float uk = 0, uk_1 = 0, ek = 0, ek_1 = 0, yk = 0, yk_1 = 0, PV = 0; 
    static uint16_t uk_pwm = 0;

    PV = Wheels.w_MR4;
    ek = w_ref - PV;

    /*Modelo real*/
    uk = 0.46713*ek-0.199371084*ek_1+uk_1;

    /*Modelo teorico*/
    // yk = 0.5134*yk_1 + 1.298*uk_1;
    // yk_1 = yk;

    uk_1 = uk;
    ek_1 = ek;

    uk_pwm = (uint16_t)fabs(uk*(4096.0/12.0));

    return uk_pwm;
}