#include "Legs.h"

Legs::Legs(byte pin, int center_pos, int bottom_pos, int top_pos)
{
  this->pin = pin;
  this->center_pos = center_pos;
  this->bottom_pos = bottom_pos;
  this->top_pos = top_pos;
}

void Legs::setup()
{
  motor.attach(pin);
  set_center();
  delay(delay_time);
}
void Legs::set_center()
{
  motor.write(center_pos);
  delay(delay_time);
}

void Legs::set_bottom()
{
  motor.write(bottom_pos);
  delay(delay_time);
}

void Legs::set_top()
{
  motor.write(top_pos);
  delay(delay_time);
}

void Legs::set_angle(int angle)
{
  motor.write(angle);
  delay(delay_time);
}

// TO TEST
void Legs::step_f()
{
  int angle;
  if (bottom_pos > center_pos)
  {
    angle = bottom_pos - 15;
  }
  else
  {
    angle = bottom_pos + 15;
  }
  set_angle(angle);
};
