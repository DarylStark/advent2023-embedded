#ifndef __ADVENT2023_H__
#define __ADVENT2023_H__

#include <Arduino.h>
#include <memory>
#include <WiFiManager.h>

class Advent2023;

/******************************************************************************/

class Advent2023State
{
protected:
    Advent2023 &_context;

public:
    Advent2023State(Advent2023 &context);
    virtual void setup() = 0;
    virtual void loop() = 0;
};

/******************************************************************************/

class Advent2023StateConnectingWifi : public Advent2023State
{
public:
    Advent2023StateConnectingWifi(Advent2023 &context);

    void setup();
    void loop();
};

/******************************************************************************/

class Advent2023StateApp : public Advent2023State
{
public:
    Advent2023StateApp(Advent2023 &context);

    void setup();
    void loop();
};

/******************************************************************************/

class Advent2023
{
    friend class Advent2023StateConnectingWifi;

private:
    std::shared_ptr<Advent2023State> __state;
    void connect_wifi();
    void transition(std::shared_ptr<Advent2023State> state);

public:
    Advent2023();
    void setup();
    void loop();
};

/******************************************************************************/

#endif