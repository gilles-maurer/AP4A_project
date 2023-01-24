#include "Humidity.hpp"
#include <stdlib.h>

//Definition of the canonical form
Humidity::Humidity() 
{
    this->m_value = 0.0;  
    this->m_type = "Humidity";
    this->m_unity = "%";
    this->m_waitTime = 0;    
}

Humidity::Humidity(const Humidity& param_hu) 
{
    this->m_value = param_hu.m_value; 
    this->m_type = param_hu.m_type;
    this->m_unity = param_hu.m_unity;
    this->m_waitTime = param_hu.m_waitTime;
}

Humidity& Humidity::operator=(const Humidity& param_hu) 
{
    this->m_value = param_hu.m_value; 
    this->m_type = param_hu.m_type;
    this->m_unity = param_hu.m_unity;
    this->m_waitTime = param_hu.m_waitTime;
    return *this; 
}

Humidity::~Humidity() 
{
}

//generate a value for the humidity
float Humidity::aleaGenValue()
{
    float answer = 0.0;
    answer = (rand()%2500 + 1000)/100.0;
    return answer; //humidity between 10.00 and 25.00  
}
