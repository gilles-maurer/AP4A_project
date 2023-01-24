#include "Scheduler.hpp"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
using namespace std;

#include <chrono> 
using namespace std::chrono;


//Definition of the canonical forms
Scheduler::Scheduler()
{
    //allocate the memory for each pointer to sensor
    m_pHu = new Humidity();
    m_pTe = new Temperature(); 
    m_pPr = new Pression(); 
    m_pLi = new Light(); 
}

Scheduler::Scheduler(const Scheduler& param_sc)
{
    m_pHu = new Humidity(); 
    *(this->m_pHu) = *(param_sc.m_pHu);

    m_pTe = new Temperature(); 
    *(this->m_pTe) = *(param_sc.m_pTe);

    m_pPr = new Pression(); 
    *(this->m_pPr) = *(param_sc.m_pPr);

    m_pLi = new Light(); 
    *(this->m_pLi) = *(param_sc.m_pLi);
}

Scheduler& Scheduler::operator=(const Scheduler& param_sc)
{
    *(this->m_pHu) = *(param_sc.m_pHu);
    *(this->m_pTe) = *(param_sc.m_pTe);
    *(this->m_pPr) = *(param_sc.m_pPr);
    *(this->m_pLi) = *(param_sc.m_pLi);
    return *this;
}

Scheduler::~Scheduler()
{
    //free the pointer to each sensor 
    delete m_pHu; 
    delete m_pTe; 
    delete m_pPr; 
    delete m_pLi; 
}

//manage all the simulation
void Scheduler::scheduler() 
{
    //create the server
    Server server; 

    //reset logs  
    server.resetLogs(m_pHu->getType());
    server.resetLogs(m_pTe->getType());
    server.resetLogs(m_pPr->getType());
    server.resetLogs(m_pLi->getType());

    //ask the user if he want to activate the console and the logs
    initializeServerParameters(server);

    //ask the user the wainting time for each sensor 
    initializeWaitTime(*m_pHu);
    initializeWaitTime(*m_pTe);
    initializeWaitTime(*m_pPr);
    initializeWaitTime(*m_pLi);

    //compute the total time for a complete loop 
    int totalLoopTime = m_pHu->getWaitTime() * m_pTe->getWaitTime() * m_pPr->getWaitTime() * m_pLi->getWaitTime();
    //initialize the loop counter 
    int counter = 0;


    //initialize the rand function
    srand(time(NULL));


    //initialize the values corresponding to the sensors
    float valueHu, valueTe;
    int valuePr;
    bool valueLi; 

    //endless loop
    while (true)
    {
        clock(1); 
        counter++; 

        //to avoid the counter to be too big
        if (counter == totalLoopTime) 
        {
            counter = 0; 
        }

        //get the data for humidity and write it 
        if (counter % m_pHu->getWaitTime() == 0)
        {
            valueHu = m_pHu->getData();
            server.consoleWrite(valueHu, m_pHu->getType(), m_pHu->getUnity());
            server.fileWrite(valueHu, m_pHu->getType(), m_pHu->getUnity());
        }
         
        //get the data for temperature and write it 
        if (counter % m_pTe->getWaitTime() == 0)
        {
            valueTe = m_pTe->getData();
            server.consoleWrite(valueTe, m_pTe->getType(), m_pTe->getUnity());
            server.fileWrite(valueTe, m_pTe->getType(), m_pTe->getUnity());
        }

        //get the data for pression and write it       
        if (counter % m_pPr->getWaitTime() == 0)
        {
            valuePr = m_pPr->getData();
            server.consoleWrite(valuePr, m_pPr->getType(), m_pPr->getUnity());
            server.fileWrite(valuePr, m_pPr->getType(), m_pPr->getUnity());
        }

        //get the data for light and write it 
        if (counter % m_pLi->getWaitTime() == 0)
        {
            valueLi = m_pLi->getData();
            server.consoleWrite(valueLi, m_pLi->getType(), m_pLi->getUnity());
            server.fileWrite(valueLi, m_pLi->getType(), m_pLi->getUnity());
        }
 
        //add a new line in the console
        server.consoleWrite();
    }
}

//wait param_time seconds
void clock(int param_time) 
{
    auto start = high_resolution_clock::now(); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    do 
    {
        stop = high_resolution_clock::now(); 
        duration = duration_cast<seconds>(stop - start); 
    } while (duration.count() < param_time); 
}

//ask the user if he want to activate the console and the logs
void initializeServerParameters(Server& param_server) 
{
    //ask the user if he wants to activate the logs
    char answer; 
    cout << "Do you want to activate the logs ? (y/n)" << endl; 
    cin >> answer; 
    if (answer == 'y') 
    {
        param_server.activateLogs();
    }
    //ask the user if he wants to activate the console
    cout << "Do you want to activate the console ? (y/n)" << endl; 
    cin >> answer; 
    if (answer == 'y') 
    {
        param_server.activateConsole();
    }
}
