#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

int main()
{
    uLCD.background_color(WHITE);
    uLCD.cls();
    uLCD.textbackground_color(WHITE);
    // basic printf demo = 16 by 18 characters on screen
    //uLCD.printf("\nHello uLCD World\n"); //Default Green on black text
    //uLCD.printf("\n  Starting Demo...");
    uLCD.text_width(2); //4X size text
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(0,1);
    uLCD.printf("106062225");

    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    
    uLCD.color(GREEN);
    for (int i=30; i>=0; --i) {
        uLCD.locate(1,2);
        uLCD.printf("%2D",i);
        wait(1);
    }
}