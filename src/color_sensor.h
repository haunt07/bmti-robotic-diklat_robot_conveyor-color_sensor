#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include <Arduino.h>

class Color
{
public:
    uint8_t redMin;
    uint8_t redMax;
    uint8_t greenMin;
    uint8_t greenMax;
    uint8_t blueMin;
    uint8_t blueMax;
    Color(
        uint8_t redMin,
        uint8_t redMax,
        uint8_t greenMin,
        uint8_t greenMax,
        uint8_t blueMin,
        uint8_t blueMax)
    {
        this->redMin = redMin;
        this->redMax = redMax;
        this->greenMin = greenMin;
        this->greenMax = greenMax;
        this->blueMin = blueMin;
        this->blueMax = blueMax;
    }

    bool operator==(const Color &other) const;
};

struct ColorRGB
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
};

class ColorSensor
{
private:
    uint8_t pinS0;
    uint8_t pinS1;
    uint8_t pinS2;
    uint8_t pinS3;
    uint8_t pinOutput;

    uint16_t rMin = 120;
    uint16_t gMin = 130;
    uint16_t bMin = 110;

    uint16_t rMax = 1800;
    uint16_t gMax = 1900;
    uint16_t bMax = 2000;

    uint16_t readSensor(bool valueS2, bool valueS3);
    uint8_t readRed();
    uint8_t readGreen();
    uint8_t readBlue();
    struct NodeColor
    {
        Color *color;
        NodeColor *next;
    };

    NodeColor *firstColor = nullptr;
    NodeColor *lastColor  = nullptr;

public:
    Color readColor();
    static Color unknownColor;
    void add(Color &color);
    void begin(uint8_t pinS0, uint8_t pinS1, uint8_t pinS2, uint8_t pinS3, uint8_t pinOutput);
    ColorRGB readRGB();
};

#endif