//
// Created by Vincent on 27.04.2022.
//
#include <iostream>
#include "Person.h"

hfu::Person::Person(const std::string& firstName, const std::string& lastName): firstName(firstName), lastName(lastName){}
hfu::Person::Person(const Person& other): Person(other.firstName, other.lastName){};
hfu::Person::Person():firstName(""), lastName(""){};
std::string hfu::Person::getFirstname(){
    return this->firstName;
}
std::string hfu::Person::getLastname(){
    return this->lastName;
}
void hfu::Person::setFirstName(std::string firstName){
    this->firstName = firstName;
}
int hfu::Person::compare(const Person& other){
    if(this->lastName < other.lastName)
        return -1;
    else if(this->lastName > other.lastName)
        return 1;
    else if(this->firstName < other.firstName)
        return -1;
    else if(this->firstName > other.firstName)
        return 1;
    return 0;
}

