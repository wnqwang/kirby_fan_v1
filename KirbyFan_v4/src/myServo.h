/**
 * @file myServo.h
 * @brief flyingpig507's servo lib for kirbyFan
 * @ingroup Servo
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <Servo.h>

#ifndef _myServo_h
#define _myServo_h

class myServo
{
private:
    Servo _myservo;
    int _initDegree;
    int _dergee;
    int _dir;
    bool _isDone;
    long lastMilli;
    int userDelay;

public:
    myServo();
    
    /*!
    @brief   servo object reference   
    @param   svo a Servo obj
    */
    void setServo(Servo svo);

    /*!
    @brief   tail sweep   
    @param   dir 1:left -1:right 0:stop
    */
    void setDirection(int dir);

};

#endif