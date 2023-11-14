#ifndef __STATIC_WEB_SERVER_H__
#define __STATIC_WEB_SERVER_H__

#include <functional>
#include <LittleFS.h>
#include <ESPAsyncWebServer.h>

#include "web_server.h"

class StaticWebServer : public WebServerRoutes
{
private:
    void __server_root_page(AsyncWebServerRequest *request);
    void __css_file(AsyncWebServerRequest *request);
    void __js_file(AsyncWebServerRequest *request);

public:
    StaticWebServer(AsyncWebServer &web_server, App &app);
    void setup();
};

#endif