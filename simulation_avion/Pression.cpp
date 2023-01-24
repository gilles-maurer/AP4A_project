#include "Pression.hpp"
#include <stdlib.h>

//Definition of the canonical form
Pression::Pression() 
{
    this->m_value = 0;
    this->m_type = "Pression";
    this->m_unity = "hPa";  
    this->m_waitTime = 0;
}

Pression::Pression(const Pression& param_pr) 
{
    this->m_value = param_pr.m_value;
    this->m_type = param_pr.m_type;
    this->m_unity = param_pr.m_unity; 
    this->m_waitTime = param_pr.m_waitTime;
}

Pression& Pression::operator=(const Pression& param_pr) 
{
    this->m_value = param_pr.m_value; 
    this->m_type = param_pr.m_type;
    this->m_unity = param_pr.m_unity;
    this->m_waitTime = param_pr.m_waitTime;
    return *this; 
}

Pression::~Pression() 
{
}

//generate a value for the pression
int Pression::aleaGenValue()
{
    return (rand()%800 + 50); // pression between 50 and 850 hPa
}
