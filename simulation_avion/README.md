Projet AP4A
================ 
Gilles Maurer - 17/10/2022

Simulation of an intern system for a plane in C++. 

The scheduler takes the informations of the 4 sensors (Humidity, Pression, Light, Temprature) and send it to the server. 

The server write the data in the consol and in the log file corresponding to each sensor. 

The user can chose if he wants to activate the consol and if he wants to activate the logs. 
The user can chose the time delay between two measures for each sensor  independently.   

Humidity : between 10 and 25 % (float)
Pression : between 50 and 850 hPa (int)
Light : 0 or 1 (bool) 
Temperature : between 20 and 30 °C (float) 

