#include "static_web_server.h"

StaticWebServer::StaticWebServer(AsyncWebServer &web_server, App &app)
    : WebServerRoutes(web_server, app)
{
}

void StaticWebServer::setup()
{
    _web_server.on(
        "/",
        std::bind(
            &StaticWebServer::__server_root_page,
            this,
            std::placeholders::_1));
    _web_server.on(
        "/static/css/main.50ad4168.css",
        std::bind(
            &StaticWebServer::__css_file,
            this,
            std::placeholders::_1));
    _web_server.on(
        "/static/js/main.js",
        std::bind(
            &StaticWebServer::__js_file,
            this,
            std::placeholders::_1));
    _web_server.onNotFound(std::bind(
        &StaticWebServer::__server_root_page,
        this,
        std::placeholders::_1));
}

void StaticWebServer::__server_root_page(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/index.html", "text/html");
}

void StaticWebServer::__css_file(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/static/css/main.50ad4168.css", "text/css");
}

void StaticWebServer::__js_file(AsyncWebServerRequest *request)
{
    request->send(LittleFS, "/static/js/main.js", "text/javascript");
}