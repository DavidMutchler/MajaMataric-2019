#ifndef BOTBALL_2019_LEGO_H
#define BOTBALL_2019_LEGO_H

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 3

#define MOTOR_FOR_TICKS  LEFT_MOTOR

#define TICKS_PER_INCH              228.0  // TODO: Find this empirically.

#define TICKS_PER_DEGREE             11.5  // TODO: Find this empirically.
#define TICKS_OVERSHOOT_AT_100       10    // TODO: Find this empirically.
#define SLEEP_MSECONDS_PER_ITERATION 10    // TODO: Try 0 (no sleep).

#define MILLISECONDS_PER_DEGREE_AT_1500  100  // TODO: Find this empirically.
#define MILLISECONDS_OVERSHOOT_AT_1500   100  // TODO: Find this empirically.

#define GYRO_DEGREES_PER_DEGREE 1000
#define GYRO_OVERSHOOT_AT_100 1000

int forward(float inches, int power);
int backward(float inches, int power);
int left(float degrees, int power);
int right(float degrees, int power);
int go1(float units_to_travel, int left_power, int right_power, float ticks_per_unit);
void lego_main();

extern int PRESS_A;

#endif //BOTBALL_2019_LEGO_H
