/**
 * @file LED.ccp
 * @brief flyingpig507's LED lib for kirbyFan
 * @ingroup Adafruit_NeoPixel
 * @author flyingpig507
 * Contact: wnqwang@gmail.com or weChat: 2216096692
 */

#include <Arduino.h>
#include <LED.h>
#include <MultiMap.h>

LED::LED(byte p, byte bright)
{
    ledCount = 2;
    _led = Adafruit_NeoPixel(ledCount, p, NEO_GRB + NEO_KHZ800);
    _led.begin();
    if (bright > 0)
    {
        _led.setBrightness(bright);
    }
}

void LED::show(byte id)
{
    _led.clear();

    switch (id)
    {
    case 0:
        setRGB(y_r_Values_0, y_g_Values_0, y_b_Values_0);
        break;

    case 1:
        setRGB(y_r_Values_1, y_g_Values_1, y_b_Values_1);
        break;

    case 2:
        setRGB(y_r_Values_2, y_g_Values_2, y_b_Values_2);
        break;

    case 3:
        setRGB(y_r_Values_3, y_g_Values_3, y_b_Values_3);
        break;
    case 4:
        setRGB(y_r_Values_4, y_g_Values_4, y_b_Values_4);
        break;

    default:
        break;
    }
}

void LED::setRGB(int R[], int G[], int B[], byte sp)
{
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < ledCount; j++)
        {
            _led.setPixelColor(j,
                               multiMap<int>(i, xValues, R, numValues),
                               multiMap<int>(i, xValues, G, numValues),
                               multiMap<int>(i, xValues, B, numValues));
        }
        _led.show();
        delay(sp);
    }
}