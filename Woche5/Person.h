//
// Created by Vincent on 21.04.2022.
//

#ifndef WOCHE5_PERSON_H
#define WOCHE5_PERSON_H
#include <string>
namespace hfu{
    class Person{
    private:
        std::string firstName;
        std::string lastName;

    public:
        Person(const std::string& firstName, const std::string& lastName);
        Person(const Person& other);
        Person();
        std::string getFirstname();
        std::string getLastname();
        void setFirstName(std::string firstName);
        int compare(const Person& other);
    };
}
#endif //WOCHE5_PERSON_H
