#include "WS2812B.h"

Color::operator uint32_t() const
{
    uint32_t rv = red * brightness;
    rv = rv << 8;
    rv += green * brightness;
    rv = rv << 8;
    rv += blue * brightness;
    return rv;
}

WS2812B::WS2812B(uint32_t gpio, uint32_t length)
    : __gpio(gpio), __length(length)
{
}

void WS2812B::setup()
{
    __component.setPin(__gpio);
    __component.begin();
    __component.updateLength(__length);
}

void WS2812B::show()
{
    __component.show();
}

void WS2812B::clear()
{
    __component.clear();
}

void WS2812B::set_pixel(uint32_t pixel_index, Color color)
{
    if (pixel_index >= __length)
        return;

    uint32_t color_code = static_cast<uint32_t>(color);
    __component.setPixelColor(pixel_index, color_code);
}

void WS2812B::fill(Color color)
{
    uint32_t color_code = static_cast<uint32_t>(color);
    __component.fill(color_code);
}