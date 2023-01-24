#include "Light.hpp"
#include <stdlib.h>


//Definition of the canonical form
Light::Light() 
{
    this->m_value = false;  
    this->m_type = "Light";
    this->m_unity = "on/off";
}

Light::Light(const Light& param_li) 
{
    this->m_value = param_li.m_value; 
    this->m_type = param_li.m_type;
    this->m_unity = param_li.m_unity;
}

Light& Light::operator=(const Light& param_li) 
{
    this->m_value = param_li.m_value; 
    this->m_type = param_li.m_type;
    this->m_unity = param_li.m_unity;
    return *this; 
}

Light::~Light() 
{
}

//generate a value for the light
bool Light::aleaGenValue()
{
    bool answer = false;
    answer = (rand()%2);
    return answer; // light on or off
}


