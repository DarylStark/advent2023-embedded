#include "MatrixFont.h"

MatrixFontCharacter::MatrixFontCharacter(PixelList pixels)
    : __pixels(pixels)
{
}

const PixelList &MatrixFontCharacter::get_pixels() const
{
    return __pixels;
}

uint16_t MatrixFontCharacter::get_width()
{
    if (__width > 0)
        return __width;

    for (const auto &pixel : __pixels)
    {
        if (pixel.first > __width)
            __width = pixel.first;
    }
    __width += 1;
    return __width;
}

MatrixFont::MatrixFont(uint16_t space_width /* = 1 */)
    : __space_width(space_width), __default()
{
}

void MatrixFont::set_character(const char &character, const MatrixFontCharacter &face)
{
    __characters[character] = face;
}

void MatrixFont::set_default(const MatrixFontCharacter &face)
{
    __default = face;
}

MatrixFontCharacter &MatrixFont::get_character_face(const char character)
{
    try
    {
        auto &c = __characters.at(character);
        return c;
    }
    catch (std::out_of_range)
    {
        return __default;
    }
}

uint16_t MatrixFont::get_space_width() const
{
    return __space_width;
}