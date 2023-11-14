#ifndef __WS2812_H__
#define __WS2812_H__

#include <Adafruit_NeoPixel.h>

class Color
{
public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    float brightness = 1.f;
    operator uint32_t() const;
};

class WS2812B
{
private:
    Adafruit_NeoPixel __component;
    uint32_t __gpio;
    uint32_t __height;
    uint32_t __length;

public:
    WS2812B(uint32_t gpio, uint32_t length);
    void setup();
    void show();
    void clear();
    void set_pixel(uint32_t pixel_index, Color color);
    void fill(Color color);
};

#endif