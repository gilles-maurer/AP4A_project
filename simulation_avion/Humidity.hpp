/**
 * @author  gilles_maurer
 * @file    Humidity.hpp
 * @date    17/10/2022
 * @brief   Child class of Sensor, humidity sensor
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

#include <string> 

class Humidity: public Sensor<float> 
{
private:

public:

    //Definition of the canonical form
    Humidity();
    Humidity(const Humidity& param_hu); 
    Humidity& operator=(const Humidity& param_hu); 
    ~Humidity();

    //generate a value for the humidity 
    float aleaGenValue() override; 
};


#endif // HUMIDITY_H