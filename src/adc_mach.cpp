#include "../include/acd_mach.hpp"

void adc_maq(void)
{
    static uint8_t estado = 0;

    switch(estado)
    {
        case 0:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (0<<MUXB) | (0<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 1;
        break;

        case 1:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (1<<MUXB) | (0<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 2;
        break;
                
        case 2:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (1<<MUXB) | (0<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 3;
        break;

        case 3:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (0<<MUXB) | (1<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 4;
        break;

        case 4:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (0<<MUXB) | (1<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 5;
        break;

        case 5:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (1<<MUXB) | (1<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 6;
        break;

        case 6:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (0<<MUXD));
            adc_select_input(0);
            estado = 7;
        break;

        case 7:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (0<<MUXB) | (0<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 8;
        break;

        case 8:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (0<<MUXB) | (0<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 9;
        break;

        case 9:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (1<<MUXB) | (0<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 10;
        break;

        case 10:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (1<<MUXB) | (0<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 11;
        break;

        case 11:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (0<<MUXB) | (1<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 12;
        break;

        case 12:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (1<<MUXA) | (0<<MUXB) | (1<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 13;
        break;

        case 13:
            sensors[estado] = adc_read();
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), (0<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD));
            adc_select_input(0);
            estado = 14;
        break;

        case 14:
            sensors[estado] = adc_read();
            estado = 15;
            adc_select_input(1); //ler canal do ADC da bateria
        break;

        case 15:
            sensors[estado] = adc_read(); //leitura da bateria
            gpio_put_masked((1<<MUXA) | (1<<MUXB) | (1<<MUXC) | (1<<MUXD), 0); //reseto o Mux
            adc_select_input(0); //ler canal do ADC da bateria
            estado = 0;
        break;

        default:
            estado = 0;
        break;
    }
}