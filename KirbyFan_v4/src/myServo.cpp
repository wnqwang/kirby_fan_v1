/**
 * @file myServo.cpp
 * @brief flyingpig507's servo lib for kirbyFan
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <myServo.h>

myServo::myServo()
{

    _initDegree = 90;
    _dergee = _initDegree;

    _isDone = false;

    lastMilli = 0;
    userDelay = 30;
    _dir = 1;
}

void myServo::setServo(Servo svo)
{
    _myservo = svo;
    _myservo.attach(9);
}

void myServo::setDirection(int dir)
{
    if (millis() - lastMilli > userDelay)
    {
        lastMilli = millis();
        if (dir == 1 || dir == -1)
        {

            if (!_isDone)
            {
                _isDone = true;
                _dergee = 90;
                _dir = dir;
            }

            // Serial.print("1 -1 _dergee : ");
            // Serial.println(_dergee);

            if (_dergee < 0 || _dergee > 180)
            {
                _dir *= -1;
            }
            _myservo.write(_dergee += _dir);
        }

        else
        {

            // Serial.print("0 0 _dergee : ");
            // Serial.println(_dergee);

            if (_dergee != 90)
            {

                if (_dergee > 90)
                {
                    _dir = -1;
                }
                else if (_dergee < 90)
                {
                    _dir = 1;
                }
                _myservo.write(_dergee += _dir);

                /* int delayD = abs(90 - _dergee);
                Serial.print("delayD : ");
                Serial.println(delayD);
                for (size_t i = 0; i < delayD; i++)
                {
                    _myservo.write(_dergee += _dir);
                    Serial.print("for _dergee : ");
                    Serial.println(_dergee);
                    delay(userDelay);
                } */
            }
            else
            {
                _isDone = false;
            }
        }
    }
}
