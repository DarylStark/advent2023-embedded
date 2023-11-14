#include "web_server.h"

WebServerRoutes::WebServerRoutes(AsyncWebServer &web_server, App &app)
    : _web_server(web_server), _app(app)
{
}