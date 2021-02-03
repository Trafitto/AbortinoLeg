
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


Servo frontFootLeft, frontFootRight, backFootLeft, backFootRight;
Servo frontLegLeft, frontLegRight, backLegLeft, backLegRight;


int ffl_home = 0;
int ffl_vertical = 100;
int ffr_home = 180;
int ffr_vertical = 100;
int bfr_home = 0;
int bfr_vertical = 100;
int bfl_home = 100;
int bfl_vertical = 0;

void setup() {
  Serial.begin(115200);
  // Foot setup
  frontFootLeft.attach(D7);
  frontFootRight.attach(D6);
  backFootLeft.attach(D5);
  backFootRight.attach(D4);

  // Foot init
  frontFootLeft.write(ffl_home);
  frontFootRight.write(ffr_home);
  backFootLeft.write(bfr_home);
  backFootRight.write(bfl_home);

}

void loop() {

    frontFootLeft.write(ffl_vertical);
    delay(50);
    frontFootRight.write(ffr_vertical);
    delay(50);
    backFootLeft.write(bfr_vertical);
    delay(50);
    backFootRight.write(bfl_vertical);
    delay(5000);
    frontFootLeft.write(ffl_home);
    delay(50);
    frontFootRight.write(ffr_home);
    delay(50);
    backFootLeft.write(bfr_home);
    delay(50);
    backFootRight.write(bfl_home);
    delay(50);
}
