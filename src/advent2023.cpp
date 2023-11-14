#include "advent2023.h"

MatrixFont matrix_font = get_subway_font();

Advent2023::Advent2023()
    : __web_server(80),
      __static_web_server(
          std::make_shared<StaticWebServer>(__web_server, *this)),
      __backend_web_server(
          std::make_shared<BackendWebServer>(__web_server, *this)),
      __led_matrix(5, 32, 8)
{
}

void Advent2023::setup()
{
    Serial.begin(115200);
    WiFiManager wm;
    wm.setClass("invert");
    bool res = wm.autoConnect("Advent 2023");

    if (res)
    {
        // Set up storage
        LittleFS.begin();

        // Set up webserver
        __static_web_server->setup();
        __backend_web_server->setup();
        __web_server.begin();

        // Set up LED Matrix
        __led_matrix.setup();
        __led_matrix.clear();
        __led_matrix.set_font("subway", matrix_font);
        __led_matrix.show();
    }
}

void Advent2023::loop()
{
}

void Advent2023::display_text(int x, const std::string text, Color color)
{
    __led_matrix.display_string(
        x, 0, text, "subway",
        color);
    __led_matrix.show();
}

void Advent2023::__scroll_text(const std::string text, Color color)
{
    uint32_t x = __led_matrix.get_width();
    uint32_t size = 0;
    while (true)
    {
        __led_matrix.clear();
        size = __led_matrix.display_string(
            x, 0, text, "subway",
            color);
        __led_matrix.show();
        x--;
        if (x == -size)
            break;
        delay(50);
    }
}

void Advent2023::__blink_text(int x, const std::string text, Color color_a, Color color_b, uint32_t repeat, uint32_t timeout)
{
    Color colors[2] = {color_a, color_b};
    int index = 0;
    for (int i = 0; i < repeat; i++)
    {
        __led_matrix.clear();
        __led_matrix.fill(colors[index % 2]);
        display_text(x, text, colors[(index + 1) % 2]);
        index++;
        delay(timeout);
    }
}

void Advent2023::wrong()
{
    __blink_text(4, "FOUT", {0, 0, 0, 0.}, {255, 0, 0, 0.1});
}

void Advent2023::correct(std::string text)
{
    __blink_text(4, "GOED", {0, 0, 0, 0.}, {0, 255, 0, 0.1});
    delay(2000);
    __led_matrix.clear();
    for (int i = 0; i < 3; ++i)
        __scroll_text(text, {0, 255, 0, 0.1});
}