#ifndef __APP_H__
#define __APP_H__

#include <WS2812B.h>

class App
{
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual void display_text(int x, const std::string text, Color color);
    virtual void wrong();
    virtual void correct(std::string text);
};

#endif