#ifndef __ADVENT2023_H__
#define __ADVENT2023_H__

#include <Arduino.h>
#include <memory>
#include <WiFiManager.h>
#include <WebServer.h>
#include <functional>

class Advent2023
{

private:
    WebServer __web_server;

    void __server_root_page();

public:
    void setup();
    void loop();
};

#endif