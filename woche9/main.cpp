#include <iostream>
#include <cassert>
#include <map>
#include "Ambulance.h"
#include "Car.h"
#include "Bicycle.h"
#include "RacingCar.h"

void testVehicle(Vehicle vehicle, int wheels, int maxSpeed){
    assert(vehicle.getWheels() == wheels);
    assert(vehicle.getMaxSpeed() == maxSpeed);
    assert(vehicle.getCurrentSpeed() == 0);
    assert(vehicle.getPosition() == 0);
}
void testAmbulance(){
    Ambulance ambulance;
    ambulance.setSpeed(100);
    assert(ambulance.getCurrentSpeed() == 100);
    ambulance.move(60);
    ambulance.move(60);
    assert(ambulance.getPosition() == 200);
    ambulance.setSpeed(200);
    assert(ambulance.getCurrentSpeed() == ambulance.getMaxSpeed());
    assert(!ambulance.isBlueLightOn());
    ambulance.switchBlueLight();
    assert(ambulance.isBlueLightOn());
}
void testCar(){
    Car car;
    assert(car.getWheels() == 4 && car.getCurrentSpeed() == 0 && car.getPosition() == 0 && car.getMaxSpeed() == 140);
    try{
        car.setSpeed(-10);
        assert(false);
    }catch(...){

    }
    car.move(100);
    assert(car.getCurrentSpeed() == 0 && car.getPosition() == 0);
}

void testBicycle(){
    Bicycle bike;
    bike.setSpeed(200);
    assert(bike.getCurrentSpeed() == bike.getMaxSpeed());
    bike.move(30);
    assert(bike.getPosition() == 30);
}

void testRacingCar(){
    RacingCar racingCar;
    racingCar.setSpeed(120);
    racingCar.move(60);
    racingCar.setSpeed(400);
    racingCar.move(30);
    assert(racingCar.getPosition() == 120+160 && racingCar.getCurrentSpeed() == 320);
}

void Race(){
    std::map<std::string, Vehicle> vehicleMap = {

    };
    vehicleMap.insert({"ambulance", Ambulance()});
    vehicleMap.insert({"car", Car()});
    vehicleMap.insert({"racingCar", RacingCar()});
    vehicleMap.insert({"bicycle", Bicycle()});
    vehicleMap["bicycle"].setSpeed(20);
    vehicleMap.find("car")->second.setSpeed(150);
    vehicleMap.find("racingCar")->second.setSpeed(200);
    vehicleMap.find("ambulance")->second.setSpeed(80);
    //4 stunden vorsprung für fahrrad
    vehicleMap.find("bicycle")->second.move(4*60);

    for(int i = 0; i < 60; i+=15){
        for(auto &vehicle : vehicleMap){
            vehicle.second.move(15);
        }

        std::cout << "------------------------" << std::endl;
        for(auto const& vehicle : vehicleMap){
            std::cout << vehicle.first << ": " << vehicle.second.getPosition() << std::endl;
        }

    }
    std::cout << "----------------FINISH LINE----------------" << std::endl;
    for(auto const& vehicle : vehicleMap){
        std::cout << vehicle.first << ": " << vehicle.second.getPosition() << std::endl;
    }

}

int main() {
    std::cout << "Starting..." << std::endl;
    testVehicle(Car(), 4, 140);
    testVehicle(Ambulance(), 4, 140);
    testVehicle(RacingCar(), 4, 320);
    testVehicle(Bicycle(), 2, 60);
    testAmbulance();
    testCar();
    testBicycle();
    testRacingCar();
    Race();
    std::cout << "Finishing..." << std::endl;
    return 0;
}
