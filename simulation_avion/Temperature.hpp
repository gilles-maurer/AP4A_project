/**
 * @author  gilles_maurer
 * @file    Temperature.hpp
 * @date    03/10/2022
 * @brief   Child class of Sensor, temperature sensor
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

#include <string>

class Temperature: public Sensor<float>
{
private:

public:

    //Definition of the canonical form
    Temperature();
    Temperature(const Temperature& param_te); 
    Temperature& operator=(const Temperature& param_te); 
    ~Temperature();

    //generate a value for the temperature
    float aleaGenValue() override; 
};

#endif // TEMPERATURE_H