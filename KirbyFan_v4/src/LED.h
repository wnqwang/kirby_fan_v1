/**
 * @file LED.h
 * @brief flyingpig507's LED lib for kirbyFan
 * @ingroup Adafruit_NeoPixel
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#ifndef _LED_h
#define _LED_h

class LED
{
private:
  byte pin;
  byte ledCount;
  Adafruit_NeoPixel _led;
  constexpr static int numValues = 6;
  int xValues[numValues] = {0, 20, 40, 60, 90, 100};

  int y_r_Values_0[numValues] = {0, 0, 0, 0, 0, 0};
  int y_g_Values_0[numValues] = {120, 0, 120, 0, 120, 0};
  int y_b_Values_0[numValues] = {0, 0, 0, 0, 0, 0};

  int y_r_Values_1[numValues] = {0, 0, 0, 0, 0, 0};
  int y_g_Values_1[numValues] = {20, 120, 20, 120, 20, 120};
  int y_b_Values_1[numValues] = {0, 0, 0, 0, 0, 0};

  int y_r_Values_2[numValues] = {20, 120, 20, 120, 20, 120};
  int y_g_Values_2[numValues] = {20, 120, 20, 120, 20, 120};
  int y_b_Values_2[numValues] = {0, 0, 0, 0, 0, 0};

  int y_r_Values_3[numValues] = {20, 120, 20, 120, 20, 120};
  int y_g_Values_3[numValues] = {0, 0, 0, 0, 0, 0};
  int y_b_Values_3[numValues] = {0, 0, 0, 0, 0, 0};

  int y_r_Values_4[numValues] = {0, 120, 0, 120, 0, 120};
  int y_g_Values_4[numValues] = {0, 0, 0, 0, 0, 0};
  int y_b_Values_4[numValues] = {0, 0, 0, 0, 0, 0};

  /*!
    @brief   set RBG value
    @param   R red array         
    @param   G green array          
    @param   B blue array         
    @param   sp play speed          
  */
  void setRGB(int R[], int G[], int B[], byte sp = 20);

public:
  /*!
  @brief   RGB led
  @param   p  Arduino pin
  @param   bright  default 0, disable. max 255
  @return  led object.
*/
  LED(byte p, byte bright = 0);

  /*!
    @brief   led on a loop
    @param   id led loop type         
  */
  void show(byte id);
};

#endif