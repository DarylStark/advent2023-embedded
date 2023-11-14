#include "advent2023.h"

Advent2023::Advent2023()
    : __web_server(80)
{
}

void Advent2023::setup()
{
    Serial.begin(115200);
    Serial.println("Connecting to WiFi");

    WiFiManager wm;
    wm.setClass("invert");
    bool res = wm.autoConnect("Advent 2023");

    if (res)
    {
        Serial.println("Setting up the app");
        __web_server.on(
            "/",
            std::bind(
                &Advent2023::__server_root_page,
                this,
                std::placeholders::_1));
        __web_server.on(
            "/static/css/main.50ad4168.css",
            std::bind(
                &Advent2023::__css_file,
                this,
                std::placeholders::_1));
        __web_server.on(
            "/static/js/main.29523ef9.js",
            std::bind(
                &Advent2023::__js_file,
                this,
                std::placeholders::_1));
        __web_server.begin();
        LittleFS.begin();
    }
}

void Advent2023::loop()
{
    delay(10);
}

void Advent2023::__server_root_page(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/index.html", "text/html");
}

void Advent2023::__css_file(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/static/css/main.50ad4168.css", "text/css");
}

void Advent2023::__js_file(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/static/js/main.29523ef9.js", "text/javascript");
}

/******************************************************************************/