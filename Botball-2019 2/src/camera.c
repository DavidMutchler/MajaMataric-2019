#include <kipr/botball.h>
#include "camera.h"

#define CENTER     80
#define GRIPLENGTH  5
#define KPLEFT    0.9
#define KPRIGHT   0.9
#define BASESPEED  50




float distance_inches(int channel)
{
    int i, j;
    int area, totalarea=0, areacount=0;
    int ocount;
    float guess, areasum=0;
    
    for(j=0;j<30;j++){
        totalarea = 0;
        camera_update();
        ocount = get_object_count(channel);
        for(i=0;i<ocount;i++){
            area = get_object_area(channel, i);
            totalarea += area;

        }
        areasum+=totalarea;
        areacount++;
        printf("Average area: %6.2f, Trials: %4d\n", areasum/areacount, areacount);
        msleep(20);
    }
    if(areasum > 0.1){
        guess = sqrt(45000.0/(areasum/areacount));
        printf("%f\n", guess);
        return guess;
    }
        msleep(500);
    return 0;
}
int find_tag(int channel)
{
    int ocount;  
    point2 pt;

    camera_open_at_res(LOW_RES);
    camera_update();
    ocount = get_object_count(channel);
    if(ocount <= 0){
        return find_tag(channel);
    }
    pt = get_object_center(channel, 0);
    if(pt.x > CENTER){
        return 1;
    }  
    else {
        return 0;
    }
}
int camera_start()
{
    int rv, i;
    rv = camera_open_at_res(LOW_RES);
    if(rv == 0){
        return camera_start();
    }
    for(i=0;i<20;i++){
        camera_update();
    }
    return rv;
}
int centered_movement(int channel)
{
    int ocount;
    float angle, rv;
    point2 center1, average;
    for(;;){
        do{
            camera_update();
            ocount = get_object_count(channel);
            printf("ocount: %d\n", ocount);
        } while(ocount <= 0);
        if(ocount <= 2){
            average = get_object_center(channel, 0);
        } else {
            center1 = get_object_center(channel, 0);
            average.x = (center1.x);
            average.y = center1.y;
        }
        rv = distance_inches(channel);
        printf("inches: %f\n", rv);
        angle = CENTER - average.x;
        printf("angle: %f average: %d\n", angle, average.x);
        if(rv <= GRIPLENGTH){
            return 1;
        }
        create_drive_direct(-(BASESPEED + angle * KPLEFT), -(BASESPEED - angle * KPRIGHT));
        msleep(20);
    }
}





