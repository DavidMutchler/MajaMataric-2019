#ifndef BOTBALL_2019_CREATE_H
#define BOTBALL_2019_CREATE_H

#define CREATE_SPEED_AT_MAX_POWER 500
#define CREATE_DEGREES_OVERSHOOT_AT_FULL_POWER 0.0  // Adjust this?
#define CREATE_INCHES_OVERSHOOT_AT_FULL_POWER 0.0  // Adjust this?
#define CREATE_SLEEP_MSECONDS_PER_ITERATION 10

#define CENTIMETERS_PER_INCH 2.54

void start_create();
void end_create();
int create_spin(float degrees, int power);
int create_forward(float inches, int power);

int CForward(float inches, int power);
int CBackward(float inches, int power);
int CLeft(float degrees, int power);
int CRight(float degrees, int power);

#endif //BOTBALL_2019_CREATE_H
