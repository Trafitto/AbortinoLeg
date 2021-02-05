
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

class BaseServo{
  public:
    byte pin;
    int bottom_pos;
    int center_pos;
    Servo motor;
    unsigned int delay_time = 50;

    BaseServo(byte pin, int center_pos, int bottom_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
    }

    void set_up(){
      motor.attach(pin);
      motor.write(center_pos);
      delay(delay_time);
    }
    void set_center(){
      motor.write(center_pos);
      delay(delay_time);
    }

    void set_bottom(){
      motor.write(bottom_pos);
      delay(delay_time);
    }
};

class LegServo: public BaseServo{
  private:
    int top_pos;
  public:
    LegServo(byte pin, int center_pos, int bottom_pos, int top_pos):BaseServo(pin, center_pos, bottom_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
      this->top_pos = top_pos;
    }

    void set_top(){
      motor.write(top_pos);
      delay(delay_time);
    }
};

class FootServo: public BaseServo{
  public:
    FootServo(byte pin, int center_pos, int bottom_pos):BaseServo(pin, center_pos, bottom_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
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
    frontFootLeft.set_bottom();
    frontFootRight.set_bottom();
    backFootLeft.set_bottom();
    backFootRight.set_bottom();

    delay(5000);
   
    frontFootLeft.set_center();
    frontFootRight.set_center();
    backFootLeft.set_center();
    backFootRight.set_center();

    delay(3000);
   
}
