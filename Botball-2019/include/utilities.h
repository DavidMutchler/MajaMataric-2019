#ifndef BOTBALL_2019_UTILITIES_H
#define BOTBALL_2019_UTILITIES_H

#include <kipr/botball.h>

#define TRUE  1
#define FALSE 0

#define MILLISECONDS_FOR_PRESS_A   300
#define MILLISECONDS_FOR_HANDS_OFF 500

void press_a_to_continue();
void press();
void servo(int port, int position);
void move_servo(int start, int change, int finish, int delay, int servo, int ud);

#endif //BOTBALL_2019_UTILITIES_H
