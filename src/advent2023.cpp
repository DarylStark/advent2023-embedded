#include "advent2023.h"

/******************************************************************************/

Advent2023State::Advent2023State(Advent2023 &context)
    : _context(context)
{
}

/******************************************************************************/

Advent2023StateConnectingWifi::Advent2023StateConnectingWifi(Advent2023 &context)
    : Advent2023State(context)
{
}

void Advent2023StateConnectingWifi::setup()
{
    Serial.begin(115200);
    Serial.println("Connecting to WiFi");

    WiFiManager wm;
    wm.setClass("invert");
    bool res = wm.autoConnect("Advent 2023");

    if (res)
        _context.transition(std::make_shared<Advent2023StateApp>(_context));
}

void Advent2023StateConnectingWifi::loop()
{
    Serial.println("You shouldn't see this");
}

/******************************************************************************/

Advent2023StateApp::Advent2023StateApp(Advent2023 &context)
    : Advent2023State(context)
{
}

void Advent2023StateApp::setup()
{
    Serial.println("You shouldn't see this");
}

void Advent2023StateApp::loop()
{
    Serial.println("Looping the app");
    delay(2000);
}

/******************************************************************************/

Advent2023::Advent2023()
    : __state(std::make_shared<Advent2023StateConnectingWifi>(*this))
{
}

void Advent2023::setup()
{
    __state->setup();
}

void Advent2023::loop()
{
    __state->loop();
}

void Advent2023::transition(std::shared_ptr<Advent2023State> state)
{
    __state = state;
}

/******************************************************************************/