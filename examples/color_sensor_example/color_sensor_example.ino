#include <color_sensor.h>

ColorSensor colorSens;
void setup(){
    Serial.begin(115200);
    colorSens.begin(A1,A2,A3,A4,A5);
    Serial.println("Inisialisasi sistem");
}

void loop(){
    ColorSensor::Color color = colorSens.readColor();
    if(color == ColorSensor::Color::Red){
        Serial.println("merah");
    }else if(color == ColorSensor::Color::Blue){
        Serial.println("biru");
    }else if(color == ColorSensor::Color::Black){
        Serial.println("hitam");
    }else{
        Serial.println("warna lain");
    }
    delay(100);
}