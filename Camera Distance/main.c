#include <kipr/botball.h>

int distanceinches();
int main()
{
    int i;
    int area, totalarea=0, areacount=0;
    int rv, ocount;
    float guess, areasum=0;
    point2 pt;
    rectangle box;
    
    rv = camera_open_at_res(LOW_RES);
    printf("Camera Open = %d\n", rv);
    for(;;){
       totalarea = 0;
       camera_update();
       ocount = get_object_count(1);
       for(i=0;i<ocount;i++){
          pt = get_object_center(1, i);
          area = get_object_area(1, i);
          totalarea += area;     
          //printf("   %d,%d", pt.x, pt.y);
       }
       areasum+=totalarea;
       areacount++;
       printf("Average area: %6.2f, Trials: %4d", areasum/areacount, areacount);
       if(areasum > 0.1){
          guess = sqrt(200.0/(areasum/areacount));
          printf(" Guess: %6.2f\n", guess);
       }
       msleep(500);
    }
    return 0;
}
int distanceinches()
{
    int i, j;
    int area, totalarea=0, areacount=0;
    int rv, ocount;
    float guess, areasum=0;
    point2 pt;
    rectangle box;
    
    rv = camera_open_at_res(LOW_RES);
    printf("Camera Open = %d\n", rv);
    for(j=0;j<70;j++){
       totalarea = 0;
       camera_update();
       ocount = get_object_count(1);
       for(i=0;i<ocount;i++){
          pt = get_object_center(1, i);
          area = get_object_area(1, i);
          totalarea += area;     
          //printf("   %d,%d", pt.x, pt.y);
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
