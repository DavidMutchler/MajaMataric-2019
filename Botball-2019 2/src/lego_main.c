#include "utilities.h"
#include "lego.h"

extern int PRESS_A;

void lego_main() {
    PRESS_A = TRUE;
    
    forward(12, 100);    
    backward(12, 100);    
    left(90, 50);    
    right(90, 50);
    
    /*
    PLAN FOR MOVEMENT - based on small robot
    f 26
    r 90
    f 13
    r 90
    b 2
    lower basket
    f 4
    sweep
    (f 13
    sweep)x4
    basket up
    f 4
    l 30
    
    l = left
    r = right
    f = forward
    b = backward
    
    
    */
    
    
    //forward(26, 100); right(90, 100)
    
    /*set_servo_position(0, 1800);
    enable_servo(0);
    press();
    
    servo(0, 600);
    servo(0, 1800);
    servo(0, 600);*/
}