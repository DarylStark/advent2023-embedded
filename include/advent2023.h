#ifndef __ADVENT2023_H__
#define __ADVENT2023_H__

#include <memory>
#include <Arduino.h>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <WS2812B_Matrix.h>
#include <SubwayFont.h>
#include "app.h"
#include "static_web_server.h"
#include "backend_web_server.h"

extern MatrixFont matrix_font;

class Advent2023 : public App
{

private:
    AsyncWebServer __web_server;
    std::shared_ptr<StaticWebServer> __static_web_server;
    std::shared_ptr<BackendWebServer> __backend_web_server;
    WS2812B_Matrix __led_matrix;
    bool __clock_mode;

    void __blink_text(int x, const std::string text, Color color_a, Color color_b, uint32_t repeat = 29, uint32_t timeout = 75);
    void __scroll_text(const std::string text, Color color);

public:
    Advent2023();
    void setup();
    void loop();
    uint16_t display_text(int x, const std::string text, Color color);
    void wrong();
    void correct(std::string text);
    bool ready() const;
};

#endif