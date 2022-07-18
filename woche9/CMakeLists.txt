cmake_minimum_required(VERSION 3.21)
project(woche9)

set(CMAKE_CXX_STANDARD 14)

add_executable(woche9 main.cpp Vehicle.cpp Ambulance.cpp Car.cpp Bicycle.cpp RacingCar.cpp)
