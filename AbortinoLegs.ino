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

// enum movementState {STOP, FORWARD, ROTATE_RIGHT, ROTATE_LEFT};
enum GeneralState
{
  IDLE,
  MOVING,
  HAND,
  HELLO,
  HAPPY,
  DANCE,
  SIT,
  COUNT
};

uint8_t state = HELLO;

class Abortino
{
private:
  // center - bottom -  top
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

    delay(1500);
  }

  // hardcoded way to say hello
  void hello()
  {
    frontLegLeft.set_top();
    frontFootLeft.set_top();

    for (int i = 0; i <= 2; i++)
    {
      frontLegLeft.set_center();
      frontLegLeft.set_top();
    }
    frontLegLeft.set_center();
    frontFootLeft.set_bottom();
  }

  uint8_t randomAction()
  {
    return static_cast<GeneralState>(rand() % COUNT);
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
  live();
  //abortinoLegs.hello();
  delay(5000);
}

/*
  Base state machine
  Need to add some input for changing the state
  TODO: Not Working, it seems that the state is null
*/
void live()
{
  Serial.write(state);
  switch (state)
  {
  case IDLE:
    delay(100);
    state = abortinoLegs.randomAction();
    break;
  case HELLO:
    abortinoLegs.hello();
    state = IDLE;
    break;
  case DEFAULT:
    state = HELLO;
    break;
  }
}