#include <kipr/botball.h>
#define LEFTMOTOR       2
#define RIGHTMOTOR      3
#define CLAWSERVO       0
#define BASKETSERVO     0
#define BASKETLOWERED 400
#define BASKETRAISED 1400
#define MSPERINCH     240


void time_forward(int left, int right, int ms, int power);
void time_left(int left, int ms, int power);
void time_right(int right, int ms, int power);
void time_backward(int left, int right, int ms, int power);
void distance_forward(float inch, int power);
void distance_backward(float inch, int power);
void degree_right(int right, int degree, int power);
void degree_left(int left, int degree, int power);
int to_color_below(int light);
int to_color_ahead(int light);
void move_servo(int start, int change, int finish, int delay, int servo, int ud);
void open(int servo);
void close(int servo);
void raise_basket();
void lower_basket();

int main()
{
   int power, inches;
   power = 750;
   inches = 6;
    
   distance_backward(inches, power);
   printf("1\n");
   msleep(inches*500);
   distance_forward(inches, power);
   printf("2\n");
   msleep(inches*500);
   getchar();
   return 236;
}

void time_forward(int left, int right, int ms, int power)
{
	motor(left,power);
	motor(right,power);
	msleep(ms);
	ao();
}
void time_left(int left, int ms, int power)
{
	motor(left,power);
	msleep(ms);
	ao();
}
void time_right(int right, int ms, int power)
{
	motor(right,power);
	msleep(ms);
	ao();
}
void time_backward(int left, int right, int ms, int power)
{
	motor(left,-power);
	motor(right,-power);
	msleep(ms);
	ao();
}
void move_servo(int start, int change, int finish, int delay, int servo, int ud)
{
   int i;
    
   for(i = start;(i*ud)<=(finish*ud);i+=change){
     set_servo_position(servo,i);
     msleep(delay);
   }
}
void raise_basket()
{
   
   move_servo(get_servo_position(BASKETSERVO), 10, BASKETRAISED, 50, BASKETSERVO, 1);
}
void lower_basket()
{
    move_servo(get_servo_position(BASKETSERVO), -10, BASKETLOWERED, 50, BASKETSERVO, -1);
}
void distance_forward(float inch, int power)
{
   move_relative_position(LEFTMOTOR, power, inch*MSPERINCH);
   move_relative_position(RIGHTMOTOR, power, inch*MSPERINCH);
}
void distance_backward(float inch, int power)
{
   move_relative_position(LEFTMOTOR, power, -inch*MSPERINCH);
   move_relative_position(RIGHTMOTOR, power, -inch*MSPERINCH);
}

