//
// Created by Vincent on 21.06.2022.
//

#include "Ambulance.h"

Ambulance::Ambulance() : Vehicle(4, 0, 140){}

bool Ambulance::isBlueLightOn() {
    return blueLightOn;
}

void Ambulance::switchBlueLight() {
    blueLightOn = !blueLightOn;
}