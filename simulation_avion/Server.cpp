#include "Server.hpp"

#include <fstream>
#include <iostream>
using namespace std;


//Definition of the canonical form
Server::Server() 
{ 
    this->m_logsActivated = false; 
    this->m_consoleActivated = false; 
}

Server::Server(const Server& param_se) 
{
    this->m_logsActivated = param_se.m_logsActivated; 
    this->m_consoleActivated = param_se.m_consoleActivated; 
}

Server& Server::operator=(const Server& param_se) 
{
    this->m_logsActivated = param_se.m_logsActivated;
    this->m_consoleActivated = param_se.m_consoleActivated;
    return *this; 
}

Server::~Server() 
{
}

//add a new line on the console 
void Server::consoleWrite()
{
    if (this->m_consoleActivated) 
    {
        cout << endl;
    }
}

//activate the console
void Server::activateConsole() 
{
    this->m_consoleActivated = true; 
}

//reset logs files
void Server::resetLogs(string param_type) 
{
    ofstream file(param_type + "_data.txt", ios::trunc);
    file.close();
}

//activate the logs
void Server::activateLogs() 
{
    this->m_logsActivated = true; 
}