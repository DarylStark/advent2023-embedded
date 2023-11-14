#include <Arduino.h>
#include "advent2023.h"

Advent2023 advent2023;

void setup()
{
    // Serial.begin(115200);

    // // WiFi Manager
    // Serial.println("Connecting to WiFi");
    // connect_wifi("Advent 2023");

    // // Connected to WiFi
    // leds.setup();
    // leds.clear();
    // font = get_subway_font();
    // leds.set_font("subway", font);

    // Serial.println("Done with setup");

    advent2023.setup();
}

void loop()
{
    advent2023.loop();
    // leds.clear();
    // uint32_t size = leds.display_string(3, 0, "20:09", "subway", {255, 255, 255, 0.01});
    // leds.show();
    // delay(100);
}
