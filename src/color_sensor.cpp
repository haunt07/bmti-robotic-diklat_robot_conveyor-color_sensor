#include "color_sensor.h"
uint16_t ColorSensor::readSensor(bool valueS2, bool valueS3 ){
    digitalWrite(pinS2,valueS2);
    digitalWrite(pinS3,valueS3);
    delayMicroseconds(100);
    return pulseIn(pinOutput,LOW,60000);
}

uint8_t ColorSensor::readRed(){
    return map(readSensor(LOW,LOW),rMin,rMax,0,255);
}

uint8_t ColorSensor::readGreen(){
    return map(readSensor(HIGH,HIGH),gMin,gMax,0,255);
}

uint8_t ColorSensor::readBlue(){
    return map(readSensor(LOW,HIGH),bMin,bMax,0,255);
}

void ColorSensor::begin(uint8_t pinS0,uint8_t pinS1,uint8_t pinS2,uint8_t pinS3,uint8_t pinOutput){
    this->pinS0 = pinS0;
    this->pinS1 = pinS1;
    this->pinS2 = pinS2;
    this->pinS3 = pinS3;
    this->pinOutput = pinOutput;

    pinMode(this->pinS0,OUTPUT);
    pinMode(this->pinS1,OUTPUT);
    pinMode(this->pinS2,OUTPUT);
    pinMode(this->pinS3,OUTPUT);
    pinMode(this->pinOutput,INPUT);

    digitalWrite(this->pinS0,HIGH);
    digitalWrite(this->pinS1,LOW);
}

ColorSensor::Color ColorSensor::readColor(){
    uint16_t colorR = readRed();
    uint16_t colorG = readGreen();
    uint16_t colorB = readBlue();
    if(colorR > 160 && colorG < 100 && colorB < 100){
        return Color::Red;
    }else if(colorR < 100 && colorG < 100 &&  colorB > 160){
        return Color::Blue;
    }else if(colorR > 120 && colorG > 120 &&  colorB > 120){
        return Color::Black;
    }else{
        return Color::Other;
    }
}