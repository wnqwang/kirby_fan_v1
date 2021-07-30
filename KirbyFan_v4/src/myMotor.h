/**
 * @file myMotor.h
 * @brief flyingpig507's motor lib for kirbyFan
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */
#include <Arduino.h>

#ifndef myMotor_h
#define myMotor_h

class myMotor
{
private:
    byte _pwmLv[4] = {0, 100, 170, 255};
    byte _inA;
    byte _inB;

public:
    /*!
    @brief   motor object make 
    @param inA pin1
    @param inB pin2
    */
    myMotor(byte inA, byte inB);

    /*!
    @brief   fan speed 
    @param id speed LV 0-2
    */
    void setMotorSpeed(byte id);
    void stopMotor();
};

#endif
