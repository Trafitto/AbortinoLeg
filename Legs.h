#ifndef Legs_h
  #define Legs_h

    #include <Arduino.h>
    #include <Servo.h>
    
    class Legs{
        private:
            byte pin;
            int bottom_pos;
            int center_pos;
            int top_pos;
            Servo motor;
            unsigned int delay_time;
        public:
            Legs(byte pin, int center_pos, int bottom_pos, int top_pos);
            void setup();
            void set_center();
            void set_bottom();
            void set_top();
            void set_angle(int angle);
            void step_f(); // TO TEST
    };

   
#endif