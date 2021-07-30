/**
 * @file main.cpp
 * @brief arduino code for kirbyFan
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <LED.h>
#include <myServo.h>
#include <myMotor.h>
#include <Arduino_APDS9960.h>

LED _led = LED(11, 20);

myServo _servo;
myMotor _motor = myMotor(6, 5);

int _gestureSelect = 0;  //fan speed LV
int _isSweep = 0; //0-stop 1-left -1-right

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);

  while (!Serial)
    ;
  if (!APDS.begin())
  {
    Serial.println("Error initializing APDS9960 sensor!");
  }
  Serial.println("Detecting gestures ...");

  _motor.setMotorSpeed(1);
  _led.show(1);

  Servo mySvo;
  _servo.setServo(mySvo);

  delay(1000);
}

void setFanLed()
{
  if (_gestureSelect < 0)
  {
    _gestureSelect = 0;
  }
  else if (_gestureSelect > 3)
  {
    _led.show(4);
    _gestureSelect = 3;
  }

  _motor.setMotorSpeed(_gestureSelect);
  _led.show(_gestureSelect);
}

void loop()
{
  // put your main code here, to run repeatedly:

  _servo.setDirection(_isSweep);

  if (APDS.gestureAvailable())
  {

    switch (APDS.readGesture())
    {
    case GESTURE_UP:
      // Serial.println("GESTURE_UP");
      _gestureSelect--;
      setFanLed();
      break;

    case GESTURE_DOWN:
      // Serial.println("GESTURE_DOWN");
      _gestureSelect++;
      setFanLed();
      break;

    case GESTURE_LEFT:
      // Serial.println("GESTURE_LEFT");
     if (_isSweep != 0)
      {
        _isSweep = 0;
      }
      else
      {
        _isSweep = 1;
      }
      break;

    case GESTURE_RIGHT:
      // Serial.println("GESTURE_RIGHT");
      if (_isSweep != 0)
      {
        _isSweep = 0;
      }
      else
      {
        _isSweep = -1;
      }

      break;

    default:
      // ignore
      break;
    }
  }
}
