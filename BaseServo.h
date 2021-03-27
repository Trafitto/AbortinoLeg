#ifndef BaseServo_h
  #define BaseServo_h

    #include <Arduino.h>
    #include <Servo.h>
    
    class BaseServo{
        public:
            byte pin;
            int bottom_pos;
            int center_pos;
            int top_pos;
            Servo motor;
            unsigned int delay_time;
            BaseServo(byte pin, int center_pos, int bottom_pos, int top_pos);
            virtual void set_home() = 0;
            void setup();
            void set_center();
            void set_bottom();
            void set_top();
            void set_angle(int angle);
    };
   
#endif