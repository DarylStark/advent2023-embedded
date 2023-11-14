#include "backend_web_server.h"

BackendWebServer::BackendWebServer(AsyncWebServer &web_server, App &app)
    : WebServerRoutes(web_server, app)
{
}

void BackendWebServer::__wrong(AsyncWebServerRequest *request)
{
    auto t = std::thread([this]()
                         { _app.wrong(); });
    t.detach();
    request->send(200, "application/json", "{ \"ok\": true }");
}

void BackendWebServer::__correct(AsyncWebServerRequest *request)
{
    int param_count = request->params();
    if (param_count != 1)
    {
        request->send(422, "application/json", "{ \"ok\": false }");
        return;
    }

    AsyncWebParameter *param = request->getParam(0);
    std::string text = param->value().c_str();

    auto t = std::thread([this, text]()
                         { _app.correct(text); });
    t.detach();
    request->send(200, "application/json", "{ \"ok\": true }");
}

void BackendWebServer::setup()
{
    _web_server.on(
        "/wrong",
        HTTP_POST,
        std::bind(
            &BackendWebServer::__wrong,
            this,
            std::placeholders::_1));
    _web_server.on(
        "/correct",
        HTTP_POST,
        std::bind(
            &BackendWebServer::__correct,
            this,
            std::placeholders::_1));
}