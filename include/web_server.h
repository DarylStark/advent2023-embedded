#ifndef __WEB_SERVER_H__
#define __WEB_SERVER_H__

#include <ESPAsyncWebServer.h>
#include "app.h"

class WebServerRoutes
{
protected:
    AsyncWebServer &_web_server;
    App &_app;

public:
    WebServerRoutes(AsyncWebServer &web_server, App &app);
    virtual void setup() = 0;
};

#endif