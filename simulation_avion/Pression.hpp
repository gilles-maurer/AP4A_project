/**
 * @author  gilles_maurer
 * @file    Pression.hpp
 * @date    17/10/2022
 * @brief   Child class of Sensor, pression sensor
 */

#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.hpp" 

#include <string>

class Pression: public Sensor<int>
{
private:

public:

    //Definition of the canonical form
    Pression();
    Pression(const Pression& param_pr); 
    Pression& operator=(const Pression& param_pr); 
    ~Pression();

    //generate a value for the pression
    int aleaGenValue() override;

};

#endif // PRESSION_H