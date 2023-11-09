#include <Arduino.h>
#include <WS2812B_Matrix.h>
#include <SubwayFont.h>

WS2812B_Matrix leds(5, 32, 8);
MatrixFont font;

void setup()
{
    Serial.begin(115200);
    leds.setup();
    leds.clear();

    font = get_subway_font();
    leds.set_font("subway", font);
}

void loop()
{
    leds.clear();
    uint32_t size = leds.display_string(3, 0, "22:39", "subway", {255, 255, 255, 0.01});
    leds.show();
    delay(100);
}
