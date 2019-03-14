#include <kipr/botball.h>

#define INCHESPERTIME 222
#define MOTORERROR   (60.0/59.0)
#define MMPERINCH    25.4
#define WAITTIME        1

float distance_forward(int speed, int distance);

int main()
{
    float rv;
    
    create_connect();
    rv = distance_forward(30, 15);
    rv = rv / MMPERINCH;
    printf("Distance: %7.3f\n", rv);
    create_disconnect();
    return 0;
}

float distance_forward(int speed, int distance)
{
    float rv;
    
    set_create_distance(0);
    while(rv <= distance * MMPERINCH * MOTORERROR){
       create_drive_direct(5*speed, 5*speed);
       msleep(WAITTIME);
       rv = get_create_distance();
    }
    return rv;
}
