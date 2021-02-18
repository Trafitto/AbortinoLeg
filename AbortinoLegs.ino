
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

// WIP
// TODO Remap pin to servo
#define PIN6 6
#define PIN5 5
#define PIN9 9
#define PIN8 8
class BaseServo{
  public:
    byte pin;
    int bottom_pos;
    int center_pos;
    int top_pos;
    Servo motor;
    unsigned int delay_time = 50;

    BaseServo(byte pin, int center_pos, int bottom_pos, int top_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
      this->top_pos = top_pos;
    }

    virtual void set_home() = 0;

    void setup(){
      motor.attach(pin);
      set_home();
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

    void set_top(){
      motor.write(top_pos);
      delay(delay_time);
    }

    void set_angle(int angle){
      motor.write(angle);
      delay(delay_time);
    }
};

class LegServo: public BaseServo{    
  public:
    LegServo(byte pin, int center_pos, int bottom_pos, int top_pos):BaseServo(pin, center_pos, bottom_pos, top_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
      this->top_pos = top_pos;
    }

    void set_home(){
      set_center();
    };

};

class FootServo: public BaseServo{
  public:
    FootServo(byte pin, int center_pos, int bottom_pos,  int top_pos):BaseServo(pin, center_pos, bottom_pos, top_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
      this->top_pos = top_pos;
    }
    void set_home(){
      set_center();
    };

    void step_f(){
      int angle;
      if (bottom_pos>center_pos){
        angle = bottom_pos - 15;
      }else{
        angle = bottom_pos + 15;
      }
      set_angle(angle);
    };
};

// center - bottom -  top

// FOOT SERVO
FootServo frontFootLeft = FootServo(D7, 100, 180, 0);
FootServo frontFootRight = FootServo(D6, 100, 0, 100);
FootServo backFootLeft = FootServo(D5, 0, 100, 0);
FootServo backFootRight = FootServo(D4, 100, 0, 100);

// LEG SERVO
LegServo frontLegLeft = LegServo(PIN6, 100, 180, 0);
LegServo frontLegRight = LegServo(PIN5, 100, 0, 180);
LegServo backLegLeft = LegServo(PIN9, 100, 180, 0);
LegServo backLegRight = LegServo(PIN8, 100, 0, 180);

void setup() {
  Serial.begin(115200);
  frontFootLeft.setup();
  frontLegLeft.setup();
  frontLegRight.setup();
}

void loop() {
  frontLegRight.set_top();
  hello();
  frontLegRight.set_center();
  delay(5000);
}

// hardcoded way to say hello J4F
void hello(){
  frontLegLeft.set_top();
  frontFootLeft.set_top();
  delay(500);
  frontLegLeft.set_center();
  delay(500);
  frontLegLeft.set_top();
  delay(500);
  frontFootLeft.set_center();
  delay(500);
  frontFootLeft.set_top();
  delay(500);
  frontLegLeft.set_center();
  delay(500);
  frontLegLeft.set_top();
  delay(500);
  frontLegLeft.set_center();
  delay(500);
  frontLegLeft.set_top();
  delay(500);
  frontLegLeft.set_center();
  delay(500);
  frontFootLeft.set_bottom();
}