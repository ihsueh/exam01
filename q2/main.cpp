#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
PwmOut PWM1(D6);

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

    /*
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    
    uLCD.color(GREEN);
    for (int i=30; i>=0; --i) {
        uLCD.locate(1,2);
        uLCD.printf("%2D",i);
        wait(1);
    }*/
    //while(1){
        PWM1.period(0.001);
        PWM1 = 0;
        bool up = true;
        while(1){
            wait(0.1);
            if(up && PWM1<1){
                PWM1 = PWM1+0.1;
            }
            else if(up && PWM1==1){
                up = false;
                PWM1 = PWM1-0,1;
            }
            else if(!up && PWM1==0){
                up = true;
                PWM1 = PWM1+0.1;
            }
            else if(!up && PWM1<1){
                PWM1 = PWM1-0.1;
            }
        }
    //}
}