#include "color_sensor.h"

Color ColorSensor::unknownColor(0, 255, 0, 255, 0, 255);

uint16_t ColorSensor::readSensor(bool valueS2, bool valueS3)
{
    digitalWrite(pinS2, valueS2);
    digitalWrite(pinS3, valueS3);
    delayMicroseconds(100);
    return pulseIn(pinOutput, LOW, 60000);
}

uint8_t ColorSensor::readRed()
{
    return map(readSensor(LOW, LOW), rMin, rMax, 0, 255);
}

uint8_t ColorSensor::readGreen()
{
    return map(readSensor(HIGH, HIGH), gMin, gMax, 0, 255);
}

uint8_t ColorSensor::readBlue()
{
    return map(readSensor(LOW, HIGH), bMin, bMax, 0, 255);
}

void ColorSensor::begin(uint8_t pinS0, uint8_t pinS1, uint8_t pinS2, uint8_t pinS3, uint8_t pinOutput)
{
    this->pinS0 = pinS0;
    this->pinS1 = pinS1;
    this->pinS2 = pinS2;
    this->pinS3 = pinS3;
    this->pinOutput = pinOutput;

    pinMode(this->pinS0, OUTPUT);
    pinMode(this->pinS1, OUTPUT);
    pinMode(this->pinS2, OUTPUT);
    pinMode(this->pinS3, OUTPUT);
    pinMode(this->pinOutput, INPUT);

    digitalWrite(this->pinS0, HIGH);
    digitalWrite(this->pinS1, LOW);
}

bool Color::operator==(const Color &other) const
{
    return redMin == other.redMin && redMax == other.redMax &&
           greenMin == other.greenMin && greenMax == other.greenMax &&
           blueMin == other.blueMin && blueMax == other.blueMax;
}

void ColorSensor::add(Color &color)
{
    if (!firstColor)
    {
        firstColor = new NodeColor{&color, nullptr};
        lastColor = firstColor;
    }
    else
    {
        lastColor->next = new NodeColor{&color, nullptr};
        lastColor = lastColor->next;
    }
}

Color ColorSensor::readColor()
{
    if (firstColor)
    {
        ColorRGB colorRGB = readRGB();
        NodeColor *nodeColor = firstColor;
        while (nodeColor)
        {
            if (colorRGB.red >= nodeColor->color->redMin && colorRGB.red <= nodeColor->color->redMax &&
                colorRGB.green >= nodeColor->color->greenMin && colorRGB.green <= nodeColor->color->greenMax &&
                colorRGB.blue >= nodeColor->color->blueMin && colorRGB.blue <= nodeColor->color->blueMax)
            {
                return *nodeColor->color;
            }
            nodeColor = nodeColor->next;
        }
    }
    return ColorSensor::unknownColor;
}

ColorRGB ColorSensor::readRGB()
{
    uint16_t colorR = readRed();
    uint16_t colorG = readGreen();
    uint16_t colorB = readBlue();
    return ColorRGB{colorR, colorG, colorB};
}