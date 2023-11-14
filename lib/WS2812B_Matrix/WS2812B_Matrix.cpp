#include "WS2812B_Matrix.h"

WS2812B_Matrix::WS2812B_Matrix(uint32_t gpio, uint32_t width, uint32_t height)
    : WS2812B(gpio, width * height), __width(width), __height(height)
{
}

uint32_t WS2812B_Matrix::get_led_index(int32_t x, int32_t y)
{
    if (x < 0 || x >= __width || y < 0 || y >= __height)
        return (__width * __height);

    uint16_t max_height = __height - 1;
    int lowest_in_column = (x * max_height) + x;
    int column_x_0 = x % 2 == 0 ? lowest_in_column + max_height : lowest_in_column;
    int minus = (x % 2 == 1 ? 1 : -1) * y;
    return column_x_0 + minus;
}

void WS2812B_Matrix::set_matrix_pixel(uint32_t x, uint32_t y, Color color)
{
    uint32_t led_index = get_led_index(x, y);
    set_pixel(led_index, color);
}

void WS2812B_Matrix::set_font(const std::string &name, MatrixFont &font)
{
    __fonts[name] = font;
}

void WS2812B_Matrix::display_pixel_list(PixelList pixel_list, const Color &color)
{
    for (const auto &pixel : pixel_list)
    {
        set_matrix_pixel(pixel.first, pixel.second, color);
    }
}

uint16_t WS2812B_Matrix::display_character(const int32_t x, const int32_t y, const char character, const std::string &font, const Color &color)
{
    MatrixFont &font_object = __fonts[font];
    if (character == ' ')
        return font_object.get_space_width();

    // Copy the pixellist for the character to a PixelList object
    MatrixFontCharacter &character_face = font_object.get_character_face(character);
    PixelList pixels;
    std::copy(std::begin(character_face.get_pixels()), std::end(character_face.get_pixels()),
              std::back_insert_iterator(pixels));

    // Add the position
    for (auto &pixel : pixels)
    {
        pixel.first += x;
        pixel.second += y;
    }

    display_pixel_list(pixels, color);
    return character_face.get_width();
}

uint16_t WS2812B_Matrix::display_string(const int32_t x, const int32_t y, const std::string &string, const std::string &font, const Color &color)
{
    int16_t pos = x;
    int16_t total = 0;
    for (const auto &character : string)
    {
        total += display_character(pos + total, y, character, font, color) + 1;
    }

    return total;
}

uint32_t WS2812B_Matrix::get_width() const
{
    return __width;
}