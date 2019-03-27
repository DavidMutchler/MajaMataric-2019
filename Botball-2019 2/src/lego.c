#include <kipr/botball.h>
#include "utilities.h"
#include "lego.h"

float BIAS = 0.0;

int forward(float inches, int power) {
    return go1(inches, power, power, TICKS_PER_INCH);
}

int backward(float inches, int power) {
    return forward(inches, -power);
}

int left(float degrees, int power) {
    return go1(degrees, -power, power, TICKS_PER_DEGREE);
}

int right(float degrees, int power) {
    return left(degrees, -power);
}

int go1(float units_to_travel, int left_power, int right_power, float ticks_per_unit) {
    float target_position, overshoot, desired_position;
    int position, position_left, position_right;

    overshoot = TICKS_OVERSHOOT_AT_100 * abs(left_power) / 100;
    target_position = units_to_travel * ticks_per_unit;
    printf("Target position: %8.1f\n", target_position);
    desired_position = target_position - overshoot;
    printf("minus overshoot: %8.1f\n", desired_position);

    clear_motor_position_counter(LEFT_MOTOR);
    clear_motor_position_counter(RIGHT_MOTOR);
    motor(LEFT_MOTOR, left_power);
    motor(RIGHT_MOTOR, right_power);
    while (1) {
        position = get_motor_position_counter(MOTOR_FOR_TICKS);
        if (abs(position) >= desired_position) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            //ao();  // CONSIDER: Try freeze, off.
            break;
        }
        if (SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_motor_position_counter(MOTOR_FOR_TICKS);
    position_left = get_motor_position_counter(LEFT_MOTOR);
    position_right = get_motor_position_counter(RIGHT_MOTOR);
    printf("Actual positions:  %6d %6d\n", position_left, position_right);
    press();
    return position;
}

int spin1(float degrees, int power) {
    return go1(degrees, power, -power, TICKS_PER_DEGREE);
}

int forward1(float inches, int power) {
    return go1(inches, power, power, TICKS_PER_INCH);
}

/*
// Uses motor position counter and power.
int spin1(float degrees, int power) {
    float target_position, overshoot, desired_position;
    int position;

    overshoot = TICKS_OVERSHOOT_AT_100 * power / 100;
    target_position = degrees * TICKS_PER_DEGREE;
    printf("Target position: %8.1f\n", target_position);
    desired_position = target_position - overshoot;
    printf("minus overshoot: %8.1f\n", desired_position);

    clear_motor_position_counter(MOTOR_FOR_TICKS);
    motor(LEFT_MOTOR, power);
    motor(RIGHT_MOTOR, -power);
    while (1) {
        position = get_motor_position_counter(MOTOR_FOR_TICKS);
        if (abs(position) >= desired_position) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            //ao();  // CONSIDER: Try freeze, off.
            break;
        }
        if (SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_motor_position_counter(MOTOR_FOR_TICKS);
    printf("Actual position:  %6d\n", position);
    press();
    return position;
} */

// Uses time and mav.
int spin2(float degrees, int speed) {
    float target_position, overshoot;
    int desired_milliseconds, position;

    // CONSIDER: Does ramp-up matter enough to worry about?

    overshoot = MILLISECONDS_OVERSHOOT_AT_1500 * speed / 1500;
    desired_milliseconds = (int) ((degrees * MILLISECONDS_PER_DEGREE_AT_1500 * 1500 / speed) - overshoot + 0.5);
    target_position = degrees * TICKS_PER_DEGREE;
    printf("Target position:  %8.1f\n", target_position);
    printf("Desired milliseconds: %6d\n", desired_milliseconds);

    clear_motor_position_counter(MOTOR_FOR_TICKS);
    mav(LEFT_MOTOR, speed);
    mav(RIGHT_MOTOR, -speed);
    msleep(desired_milliseconds);
    ao();

    msleep(1000);
    position = get_motor_position_counter(MOTOR_FOR_TICKS);
    printf("Actual position:  %6d\n", position);
    press();
    return position;}

// Uses gyro_z and power.
int spin3(float degrees, int power) {
    float target_position, overshoot, total;
    int desired_total, position;

    overshoot = GYRO_OVERSHOOT_AT_100 * power / 100;
    desired_total = (int) ((degrees * GYRO_DEGREES_PER_DEGREE) - overshoot + 0.5);
    target_position = degrees * TICKS_PER_DEGREE;
    printf("Target position: %8.1f\n", target_position);
    printf("Desired total: %6d\n", desired_total);

    clear_motor_position_counter(MOTOR_FOR_TICKS);
    motor(LEFT_MOTOR, power);
    motor(RIGHT_MOTOR, -power);
    total = 0;
    while (1) {
        total = total + abs(gyro_z() - BIAS);
        if (total >= desired_total) {
            ao();  // CONSIDER: Try freeze, off.
            break;
        }
        if (SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_motor_position_counter(MOTOR_FOR_TICKS);
    printf("Actual position:  %6d\n", position);
    press();
    return position;}
