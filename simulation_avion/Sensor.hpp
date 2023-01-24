/**
 * @author  gilles_maurer
 * @file    Sensor.hpp
 * @date    17/10/2022
 * @brief   Parent class of all sensors, virtual class
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <string>

template <class T> class Sensor 
{
protected:
    T m_value;
    std::string m_type; 
    std::string m_unity; 
    int m_waitTime; //time between two measures
    virtual T aleaGenValue() = 0; 

public: 

    //Definition of the canonical form
    Sensor() {}

    Sensor(const Sensor<T>& param_se) 
    {
        this->m_value = param_se.m_value; 
        this->m_type = param_se.m_type;
        this->m_unity = param_se.m_unity;
        this->m_waitTime = param_se.m_waitTime;
    }

    Sensor<T>& operator=(const Sensor<T>& param_se) 
    {
        this->m_value = param_se.m_value;
        this->m_type = param_se.m_type;
        this->m_unity = param_se.m_unity;
        this->m_waitTime = param_se.m_waitTime;
        return *this;
    } 

    ~Sensor() {}

    //get the value of the sensor : call the aleaGenValue() function of the right child
    T getData()
    {
        return this->aleaGenValue();  
    }

    //get the type of the sensor
    std::string getType()
    {
        return this->m_type;
    }

    //get the unity of the sensor
    std::string getUnity()
    {
        return this->m_unity; 
    }

    //set the wait time between two measures for the sensor
    void setWaitTime(int param_time) 
    {
        this->m_waitTime = param_time; 
    }

    //get the wait time between two measures for the sensor
    int getWaitTime() 
    {
        return this->m_waitTime;
    }

};

#endif // SENSOR_H


