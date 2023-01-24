/**
 * @author  gilles_maurer
 * @file    Scheduler.hpp
 * @date    17/10/2022
 * @brief   Scheduler class, initialize the simulation parameters,
 *          manage the sensors and the server, use the clock to regulate it 
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp"
#include "Sensor.hpp"

#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Temperature.hpp"

#include <iostream>

class Scheduler
{
private:

    Sensor<float>* m_pHu;
    Sensor<float>* m_pTe; 
    Sensor<int>* m_pPr;
    Sensor<bool>* m_pLi; 
    
public:
    //Definition of the canonical form
    Scheduler();
    Scheduler(const Scheduler& param_sc);
    Scheduler& operator=(const Scheduler& param_sc);
    ~Scheduler();

    //manage all the simulation
    void scheduler();   
};

//wait param_time seconds
void clock(int param_time);

//ask the user if he want to activate the console and the logs
void initializeServerParameters(Server& param_server);

//ask the user the waiting time for the sensor in parameter 
template <typename T>
void initializeWaitTime(Sensor<T>& param_sensor) {
    int waitTime;
    std::cout << "Enter the waiting time for the " << param_sensor.getType() << " sensor (in seconds): ";
    std::cin >> waitTime;
    param_sensor.setWaitTime(waitTime);
}

#endif // SCHEDULER_H