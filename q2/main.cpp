#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
PwmOut PWM1(D6);
AnalogIn Ain(A0);
Serial pc( USBTX, USBRX );

int main()
{
    uLCD.background_color(WHITE);
    uLCD.cls();
    uLCD.textbackground_color(WHITE);
    uLCD.text_width(2); //4X size text
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(0,1);
    uLCD.printf("106062225");
    uLCD.line(20, 20, 20, 100, BLACK);
    uLCD.line(20, 100, 100, 100, BLACK);
    uLCD.line(100, 100, 100, 20, BLACK);
    uLCD.line(100, 20, 20, 20, BLACK);

    PWM1.period(0.001);
    PWM1 = 0;

    bool up = true;
    for(int i=0;; i++){
        pc.printf("%1.3f\r\n", Ain);
        wait(0.1);
        if(i==10){
            i = 0;
            up = !up;
        }
        if(up){
            PWM1 = PWM1 + 0.1;
        }
        else{
            PWM1 = PWM1 - 0.1;
        }
    }

}