#include "Temperature.hpp"
#include <stdlib.h>

//Definition of the canonical form
Temperature::Temperature() 
{
    this->m_value = 0.0;  
    this->m_type = "Temperature";
    this->m_unity = "C";
    this->m_waitTime = 0;
}

Temperature::Temperature(const Temperature& param_te) 
{
    this->m_value = param_te.m_value; 
    this->m_type = param_te.m_type;
    this->m_unity = param_te.m_unity;
    this->m_waitTime = param_te.m_waitTime;
}

Temperature& Temperature::operator=(const Temperature& param_te)
{
    this->m_value = param_te.m_value; 
    this->m_type = param_te.m_type;
    this->m_unity = param_te.m_unity;
    this->m_waitTime = param_te.m_waitTime;
    return *this; 
}

Temperature::~Temperature() 
{
}

//generate a value for the temperature
float Temperature::aleaGenValue()
{
    float answer = 0.0;
    answer = (rand()%1000 + 2000)/100.0;
    return answer; //temp between 20.00 and 30.00
}