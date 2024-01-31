#include "../include/motores.hpp"


void move_foward(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,true);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_off(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}
void move_backward(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,true);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,true);
    extender.flush_output();
}

void move_right(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,true);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_left(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,true);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,true);
    extender.flush_output();
}

void move_foward_left(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,true);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_foward_right(void)
{

    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_backward_left(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,true);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();

}

void move_backward_right(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,true);
    extender.flush_output();
}

void move_turning_left(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_turning_right(void)
{
    //direita1 frent
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,true);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,true);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,true);
    extender.flush_output();
}

void move_curved(uint16_t pwm_value1, uint16_t pwm_value2, uint16_t pwm_value3, uint16_t pwm_value4)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,true);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();

    update_pwm(pwm_value1, pwm_value2, pwm_value3, pwm_value4);
}

void move_lateral_arc_L_fow(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,true);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,true);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void move_lateral_arc_R_fow(void)
{
    //direita1 frent
    
    extender.set_output_bit_for_pin(AIN1,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN2,false);
    extender.flush_output();

    //direita2 frent
    extender.set_output_bit_for_pin(BIN1,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN2,false);
    extender.flush_output();
    
    //esquerda1 frent
    extender.set_output_bit_for_pin(AIN3,true);
    extender.flush_output();
    extender.set_output_bit_for_pin(AIN4,false);
    extender.flush_output();

    //esquerda2 frent
    extender.set_output_bit_for_pin(BIN3,false);
    extender.flush_output();
    extender.set_output_bit_for_pin(BIN4,false);
    extender.flush_output();
}

void update_pwm(uint16_t pwm_value1, uint16_t pwm_value2, uint16_t pwm_value3, uint16_t pwm_value4)
{
    pwm_set_gpio_level(PWMA, pwm_value1); //left foward
    pwm_set_gpio_level(PWMB, pwm_value2); //left back
    pwm_set_gpio_level(PWMC, pwm_value3); //right foward
    pwm_set_gpio_level(PWMD, pwm_value4); //right back
}

void motors_test_move(void)
{
    static uint8_t estado = 0;

    switch (estado)
    {
        case 0:
            move_foward();
            estado = 1;
            break;
        
        case 1:
            move_backward();
            estado = 2;
            break;

        case 2:
            move_left();
            estado = 3;
            break;

        case 3:
            move_right();
            estado = 4;
            break;

        case 4:
            move_foward_left();
            estado = 5;
            break;
        
        case 5:
            move_foward_right();
            estado = 6;
            break;
        
        case 6:
            move_backward_right();
            estado = 7;
            break;
        
        case 7:
            move_backward_left();
            estado = 8;
            break;
        
        case 8:
            move_turning_right();
            estado = 9;
            break;
        
        case 9:
            move_turning_left();
            estado = 10;
            break;

        case 10:
            move_lateral_arc_L_fow();
            estado = 11;
            break;

        case 11:
            move_lateral_arc_R_fow();
            estado = 0;
            break;

        default:
            estado = 0;
            break;
    }
}