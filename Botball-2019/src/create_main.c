#include <kipr/botball.h>
#include "utilities.h"
#include "create.h"
#include "camera.h"

extern int PRESS_A;

int create_main() {
    PRESS_A = TRUE;

    start_create();
    camera_start();
    printf("%d\n", find_tag(0));
    printf("%d\n", find_tag(1));
    /*CLeft(90, 25);
    //CRight(90, 25);
    enable_servo(0);
    //set_servo_position(0,700);
    servo(0,700);
    msleep(1000);
    CBackward(18, 50);
    //set_servo_position(0,1100);
    servo(0,1100);
    CForward(15, 50);
    CLeft(90, 25);
    CBackward(7, 50);
    set_servo_position(0,700);
    msleep(300);
    CForward(19,15);
    CRight(90,25);
        servo(0,700);
    msleep(1000);
    CBackward(18, 50);
    //set_servo_position(0,1100);
    servo(0,1100);
    CForward(15, 50);
    CLeft(90, 25);
    CBackward(7, 50);
    set_servo_position(0,700);
    msleep(300);
    end_create();
	disable_servo(0);
    return 300;*/
    return 0;
}