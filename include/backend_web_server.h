#ifndef __BACKEND_WEB_SERVER_H__
#define __BACKEND_WEB_SERVER_H__

#include <functional>
#include <thread>
#include <ESPAsyncWebServer.h>

#include "web_server.h"

class BackendWebServer : public WebServerRoutes
{
private:
    void __wrong(AsyncWebServerRequest *request);
    void __correct(AsyncWebServerRequest *request);

public:
    BackendWebServer(AsyncWebServer &web_server, App &app);
    void setup();
};

#endif