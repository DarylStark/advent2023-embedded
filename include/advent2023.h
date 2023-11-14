#ifndef __ADVENT2023_H__
#define __ADVENT2023_H__

#include <Arduino.h>
#include <functional>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

class Advent2023
{

private:
    AsyncWebServer __web_server;

    void __server_root_page(AsyncWebServerRequest *request);
    void __css_file(AsyncWebServerRequest *request);
    void __js_file(AsyncWebServerRequest *request);

public:
    Advent2023();
    void setup();
    void loop();
};

#endif