#ifndef __WS2812_MATRIX_H__
#define __WS2812_MATRIX_H__

#include <string>
#include <map>
#include <WS2812B.h>
#include <MatrixFont.h>

class WS2812B_Matrix : public WS2812B
{
private:
    uint32_t __width;
    uint32_t __height;
    std::map<std::string, MatrixFont> __fonts;

public:
    WS2812B_Matrix(uint32_t gpio, uint32_t width, uint32_t height);
    uint32_t get_led_index(int32_t x, int32_t y);
    void set_matrix_pixel(uint32_t x, uint32_t y, Color color);
    void set_font(const std::string &name, MatrixFont &font);
    void display_pixel_list(PixelList pixel_list, const Color &color);
    uint16_t display_character(const int32_t x, const int32_t y, const char character, const std::string &font, const Color &color);
    uint16_t display_string(const int32_t x, const int32_t y, const std::string &string, const std::string &font, const Color &color);
};

#endif