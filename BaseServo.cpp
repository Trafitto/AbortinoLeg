#include "BaseServo.h" 

BaseServo::BaseServo(byte pin, int center_pos, int bottom_pos, int top_pos){
      this->pin = pin;
      this->center_pos = center_pos;
      this->bottom_pos = bottom_pos;
      this->top_pos = top_pos;
}

 void BaseServo::setup(){
      motor.attach(pin);
      set_home();
      delay(delay_time);
    }
    void BaseServo::set_center(){
      motor.write(center_pos);
      delay(delay_time);
    }

    void BaseServo::set_bottom(){
      motor.write(bottom_pos);
      delay(delay_time);
    }

    void BaseServo::set_top(){
      motor.write(top_pos);
      delay(delay_time);
    }

    void BaseServo::set_angle(int angle){
      motor.write(angle);
      delay(delay_time);
    }

