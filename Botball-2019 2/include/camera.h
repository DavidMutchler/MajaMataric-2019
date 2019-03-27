#ifndef BOTBALL_2019_CREATE_MAIN_H
#define BOTBALL_2019_CREATE_MAIN_H

int find_tag(int channel);   // returns 0 if object is on left, 1 if object is on right
int object_center(int channel, int object);
int camera_start();
float distance_inches(int channel);
int centered_movement(int channel);

#endif //BOTBALL_2019_CREATE_MAIN_H
