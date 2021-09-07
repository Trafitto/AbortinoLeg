#include "Legs.h"

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

// center - bottom -  top

class Abortino
{
private:
  // FOOT SERVO
  Legs frontFootLeft = Legs(D7, 100, 180, 0);
  Legs frontFootRight = Legs(D6, 100, 0, 100);
  Legs backFootLeft = Legs(D5, 0, 100, 0);
  Legs backFootRight = Legs(D4, 100, 0, 100);
  // LEG SERVO
  Legs frontLegLeft = Legs(PIN6, 100, 180, 0);
  Legs frontLegRight = Legs(PIN5, 100, 0, 180);
  Legs backLegLeft = Legs(PIN9, 100, 180, 0);
  Legs backLegRight = Legs(PIN8, 100, 0, 180);

public:
  Abortino()
  {
  }
  void setup()
  {
    // FRONT LEFT
    frontFootLeft.setup();
    frontLegLeft.setup();

    // FRONT RIGTH
    frontLegRight.setup();
    frontFootRight.setup();

    // BACK LEFT
    backFootLeft.setup();
    backLegLeft.setup();

    // BACK RIGTH
    backFootRight.setup();
    backLegRight.setup();
  }

  // hardcoded way to say hello J4
  void hello()
  {
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
};

Abortino abortinoLegs = Abortino();

void setup()
{
  Serial.begin(115200);

  abortinoLegs.setup();
}

void loop()
{
  abortinoLegs.hello();
  delay(5000);
}
