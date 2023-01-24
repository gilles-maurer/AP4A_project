/**
 * @author  gilles_maurer
 * @file    Server.hpp
 * @date    17/10/2022
 * @brief   Server class, write data in a file and in the console
 */

#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"

#include <string>
#include <fstream>
#include <iostream>

class Server 
{
private:
    bool m_logsActivated;
    bool m_consoleActivated;
    
public:

    //Definition of the canonical form
    Server();
    Server(const Server& param_se);
    Server& operator=(const Server& param_se);
    ~Server();

    //write the data on the console
    template <typename T>
    void consoleWrite(T param_value, std::string param_type, std::string param_unity)
    {
        if (this->m_consoleActivated) 
        {
            std::cout << param_type + " : ";
            std::cout << param_value; 
            std::cout << " " + param_unity << std::endl;
        }
    }

    //add a new line on the console
    void consoleWrite();

    //activate the console
    void activateConsole();
    
    //write the data in the file
    template <typename T>
    void fileWrite(T param_value, std::string param_type, std::string param_unity)
    {
        if (this->m_logsActivated) 
        {
            std::ofstream file(param_type + "_data.txt", std::ios::app);
            file << param_type + " : ";
            file << param_value;
            file << " " + param_unity << std::endl;
            file.close();
        }
    }

    //reset logs files
    void resetLogs(std::string param_type);

    //activate the logs
    void activateLogs();
};

#endif // SERVER_H


