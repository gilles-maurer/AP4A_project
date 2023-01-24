cmake_minimum_required(VERSION 3.17)

project(simulation_avion)

add_executable(simulation_avion main.cpp Scheduler.hpp Scheduler.cpp Humidity.hpp Humidity.cpp Light.hpp Light.cpp Pression.hpp Pression.cpp Sensor.hpp Server.cpp Server.hpp Temperature.cpp Temperature.hpp)