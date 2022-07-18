//
// Created by Vincent on 21.06.2022.
//

#include "Vehicle.h"
#include <stdexcept>
Vehicle::Vehicle(int wheels, int currentSpeed, int maxSpeed) :
    wheels(wheels), currentSpeed(currentSpeed), maxSpeed(maxSpeed), position(0){}
int Vehicle::getCurrentSpeed() const{
    return currentSpeed;
}
int Vehicle::getMaxSpeed() const{
    return maxSpeed;
}

int Vehicle::getPosition() const {
    return position;
}

int Vehicle::getWheels() const{
    return wheels;
}

void Vehicle::setSpeed(int velocity) {
    if(velocity < 0)
        throw std::invalid_argument("velocity needs to be above 0");
    if(velocity < maxSpeed)
        this->currentSpeed = velocity;
    else
        this->currentSpeed = maxSpeed;
}

void Vehicle::move(int minutes) {
    position += (minutes*getCurrentSpeed())/60;
}