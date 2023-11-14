#include "advent2023.h"

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
        __web_server.on("/", std::bind(&Advent2023::__server_root_page, this));
        __web_server.begin();
    }
}

void Advent2023::loop()
{
    __web_server.handleClient();
    delay(10);
}

void Advent2023::__server_root_page()
{
    __web_server.send(200, "text/html", "<p>Frontpage</p>");
}

/******************************************************************************/