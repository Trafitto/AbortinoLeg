
#include <Servo.h>

// NODEmcu PIN
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13

// TODO: Find better name for vertical and refator FootServo to be general 
class FootServo{
  
  private:
    byte pin;
    int home_pos;
    int vertical_pos;
    Servo motor;
    unsigned int delay_time = 50;
  public:
     FootServo(byte pin, int home_pos, int vertical_pos){
      this->pin = pin;
      this->home_pos = home_pos;
      this->vertical_pos = vertical_pos;
    }
    
    void set_up(){
      motor.attach(pin);
      motor.write(home_pos);
      delay(delay_time);
    }
    
    void set_home(){
      motor.write(home_pos);
      delay(delay_time);
    }

    void set_vertical(){
      motor.write(vertical_pos);
      delay(delay_time);
    }
};


FootServo frontFootLeft = FootServo(D7, 0, 100);
FootServo frontFootRight = FootServo(D6, 180, 100);
FootServo backFootLeft = FootServo(D5, 0, 100);
FootServo backFootRight = FootServo(D4, 100, 0);

Servo frontLegLeft, frontLegRight, backLegLeft, backLegRight;

void setup() {
  Serial.begin(115200);
  
  frontFootLeft.set_up();
  frontFootRight.set_up();
  backFootLeft.set_up();
  backFootRight.set_up();
}

void loop() {
    frontFootLeft.set_vertical();
    frontFootRight.set_vertical();
    backFootLeft.set_vertical();
    backFootRight.set_vertical();

    delay(5000);
   
    frontFootLeft.set_home();
    frontFootRight.set_home();
    backFootLeft.set_home();
    backFootRight.set_home();

    delay(3000);
   
}
