/**
 * @author  gilles_maurer
 * @file    Light.hpp
 * @date    17/10/2022
 * @brief   Child class of Sensor, light sensor
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

#include <string>

class Light: public Sensor<bool>
{
private:

public:
    
    //Definition of the canonical form
    Light();
    Light(const Light& param_li); 
    Light& operator=(const Light& param_li); 
    ~Light();

    //generate a value for the light
    bool aleaGenValue() override; 
};

#endif // LIGHT_H