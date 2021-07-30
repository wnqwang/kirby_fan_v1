/**
 * @file myMotor.cpp
 * @brief flyingpig507's motor lib for kirbyFan
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <myMotor.h>

myMotor::myMotor(byte inA, byte inB)
{
    _inA = inA;
    _inB = inB;
    pinMode(_inA, OUTPUT);
    pinMode(_inB, OUTPUT);
}

void myMotor::setMotorSpeed(byte id)
{
    //motor.motorGo(_pwmLv[id]);
    digitalWrite(_inA, LOW);
    analogWrite(_inB, _pwmLv[id]);
}

void myMotor::stopMotor()
{
    digitalWrite(_inA, LOW);
    digitalWrite(_inB, LOW);
}