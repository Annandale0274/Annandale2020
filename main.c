#include <kipr/wombat.h>

void turn_right_90();
void turn_left_90();
void turn_left_180();
void go_forward(int milliseconds);
void go_back(int milliseconds);

int main()
{
    int distance = 0;
    int color = 1;
    int distance_2 = 3;
    enable_servos();
    set_servo_position(0,800);
    set_servo_position(1,980);
    set_servo_position(2,1888);
    set_servo_position(3,0);
    
    motor(0,100);
    motor(3,-100);
    msleep(980);
    while(analog(distance) < 2900) {
        motor(0,-100);
        motor(3,-100);
    }
    go_forward(200);
    set_servo_position(0,1200); 
    msleep(300);
    
    motor(0,-100);
    motor(3,100);
    msleep(545);
    set_servo_position(1,450);
    msleep(300);
    go_forward(2100);
    turn_left_90();
    go_forward(1000);
    set_servo_position(1,1000);
    go_forward(2000);
    
    while(analog(distance) < 2600) {
        if(analog(color) >= 4000) {
            motor(0,-90);
            motor(3,-70);
        }
        else {
            motor(0, -70);
            motor(3,-90);
        }
    }
        ao();
    motor(0,-100);
    msleep(1000);
                       
    set_servo_position(2,715);
    msleep(500);
    
     set_servo_position(3,429);
    msleep(500);
    go_forward(1500);
    
    while(analog(distance_2) < 2600) {
        if(analog(color) >= 4000) {
            motor(0,-90);
            motor(3,-70);
        }
        else {
            motor(0, -70);
            motor(3,-90);
        }
    }
        ao();
    
    
    return 0;
}

void turn_right_90() {
        motor(0,100);
        motor(3,-100);
    msleep(1070);    
    ao();
}

void turn_left_90() {
        motor(0,-100);
        motor(3,100);
    msleep(1070);    
    ao();
}

void go_forward(int milliseconds) {
    motor(0,-100);
    motor(3,-100);
    msleep(milliseconds);
    ao();
}

void go_back(int milliseconds) {
    motor(0,100);
    motor(3,100);
    msleep(milliseconds);
    ao();
}

void turn_left_180() {
        motor(0,-100);
        motor(3,100);
    msleep(2140);    
    ao();
}
