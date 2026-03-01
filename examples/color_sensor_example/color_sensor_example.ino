#include <color_sensor.h>

ColorSensor colorSens;
Color colorRed(150, 255, 0, 90, 0, 90);
Color colorBlue(0, 90, 0, 90, 150, 255);
Color colorBlack(110, 255, 110, 255, 110, 255);

void setup()
{
    Serial.begin(115200);
    colorSens.add(colorRed);
    colorSens.add(colorBlue);
    colorSens.add(colorBlack);
    colorSens.begin(A1, A2, A3, A4, A5);
    Serial.println("Inisialisasi sistem");
}

void loop()
{
    Color color = colorSens.readColor();
    if (color == colorRed)
    {
        Serial.println("merah");
    }
    else if (color == colorBlue)
    {
        Serial.println("biru");
    }
    else if (color == colorBlack)
    {
        Serial.println("hitam");
    }
    else
    {
        Serial.println("warna lain");
    }
    delay(100);
}