#include <kipr/botball.h>

#define INCHESPERTIME 222

int distance_forward(int speed, int distance);

int main()
{
    int rv;
    rv = create_connect();
    printf("%d\n", rv);
    rv = distance_forward(20, 9);
    printf("%d\n", rv);
    create_disconnect();
    return 0;
}
int distance_forward(int speed, int distance)
{
    int rv;
    set_create_distance(0);
    create_drive_direct(6*speed, 5*speed);
    msleep(distance*INCHESPERTIME);
    rv = get_create_distance();
    return rv;
}