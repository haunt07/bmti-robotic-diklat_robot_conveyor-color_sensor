#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include<Arduino.h>

class ColorSensor{
    private:
    uint8_t pinS0;
    uint8_t pinS1;
    uint8_t pinS2;
    uint8_t pinS3;
    uint8_t pinOutput;

    uint16_t rMin=120;
    uint16_t gMin=130;
    uint16_t bMin=110;

    uint16_t rMax=1800;
    uint16_t gMax=1900;
    uint16_t bMax=2000;

    uint16_t rangeColorParam = 20;

    uint16_t readSensor(bool valueS2, bool valueS3 );
    uint8_t readRed();
    uint8_t readGreen();
    uint8_t readBlue();

    public:
    enum class Color{Red, Blue, Black, Other};
    void begin(uint8_t pinS0,uint8_t pinS1,uint8_t pinS2,uint8_t pinS3,uint8_t pinOutput);
    Color readColor();
};

#endif