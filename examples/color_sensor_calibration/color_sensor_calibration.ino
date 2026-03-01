#include <color_sensor.h>

ColorSensor colorSens;

void setup()
{
    Serial.begin(115200);
    colorSens.begin(A1, A2, A3, A4, A5);
    Serial.println("Inisialisasi sistem");
}

void loop()
{
    ColorRGB color = colorSens.readRGB();
    Serial.print("red : ");
    Serial.print(color.red);
    Serial.print("\tgreen : ");
    Serial.print(color.green);
    Serial.print("\tblue : ");
    Serial.println(color.blue);
    delay(100);
}