#include <WiFiManager.h>
#include "connect_wifi.h"

void connect_wifi(std::string ap_name)
{
    WiFiManager wm;
    wm.setClass("invert");
    bool res = wm.autoConnect(ap_name.c_str());

    if (!res)
    {
        Serial.println("Failed to connect");
        ESP.restart();
    }
    else
    {
        Serial.println("Wifi connected");
    }
}