#include <kipr/botball.h>

int find_tag(int channel);   // returns 0 if object is on left, 1 if object is on right
int object_center(int channel, int object);
int camera_start();


int distanceinches(int channel)
{
    int i, j;
    int area, totalarea=0, areacount=0;
    int rv, ocount;
    float guess, areasum=0;

    rv = camera_open_at_res(LOW_RES);
    printf("Camera Open = %d\n", rv);
    for(j=0;j<70;j++){
        totalarea = 0;
        camera_update();
        ocount = get_object_count(channel);
        for(i=0;i<ocount;i++){
            area = get_object_area(channel, i);
            totalarea += area;

        }
        areasum+=totalarea;
        areacount++;
        printf("Average area: %6.2f, Trials: %4d", areasum/areacount, areacount);
        if(areasum > 0.1){
            guess = sqrt(200.0/(areasum/areacount));
            return guess;
        }
        msleep(500);
    }
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
    if(pt.x > 80){
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
    int i, j, k, ocount;
    point2 center1, center2, center3, average;
    
    camera_update();
    ocount = get_object_count(channel);
    if(ocount <= 0){
        return 0;
    }
    
       
}


