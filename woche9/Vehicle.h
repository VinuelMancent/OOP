//
// Created by Vincent on 21.06.2022.
//

#ifndef WOCHE9_VEHICLE_H
#define WOCHE9_VEHICLE_H


class Vehicle {
private:
    int wheels;
    int currentSpeed;
    int maxSpeed;
    double position;
public:
    Vehicle(int wheels, int currentSpeed, int maxSpeed);
    int getWheels() const;
    int getCurrentSpeed() const;
    int getMaxSpeed() const;
    int getPosition() const;
    void setSpeed(int velocity);
    void move(int minutes);
};


#endif //WOCHE9_VEHICLE_H
