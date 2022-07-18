//
// Created by Vincent on 21.06.2022.
//

#ifndef WOCHE9_AMBULANCE_H
#define WOCHE9_AMBULANCE_H

#include "Vehicle.h"
class Ambulance : public Vehicle{
private:
    bool blueLightOn;
public:
    Ambulance();
    bool isBlueLightOn();
    void switchBlueLight();
};


#endif //WOCHE9_AMBULANCE_H
