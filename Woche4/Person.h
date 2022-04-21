//
// Created by Vincent on 21.04.2022.
//

#ifndef WOCHE4_PERSON_H
#define WOCHE4_PERSON_H
#include <string>
namespace hfu{
    class Person{
    private:
        std::string firstName;
        std::string lastName;

    public:
        Person(const std::string& firstName, const std::string& lastName): firstName(firstName), lastName(lastName){}
        std::string getFirstname();
        std::string getLastname();
        int compare(const Person& other);
    };
}
#endif //WOCHE4_PERSON_H
