#include <iostream>
#include <cassert>
#include "Person.h"
#include "SimpleVector.h"

typedef hfu::SimpleVector<std::string> WordSequence;



hfu::Person* createArray() {
    hfu::Person* result = new hfu::Person[4];
    result[0]=hfu::Person("Minnie", "Maus");
    result[1]=hfu::Person("Daisy", "Duck");
    result[2]=hfu::Person("Donald", "Duck");
    result[3]=hfu::Person("Micky", "Maus");
    return result;
}

template <typename T> void sort(T* array, int size) {
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(array[i].compare(array[j]) > 0) {
                auto temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

void printArray(hfu::Person* personen, int size){
    for(int i = 0; i < size; i++){
        std::cout << personen[i].getFirstname() << std::endl;
    }
}

void testTemplateSortPerson(){
    int size = 4;
    hfu::Person* persons = createArray();
    sort(persons, size);
    assert((persons[0]).getFirstname() == "Daisy");
    assert((persons[1]).getFirstname() == "Donald");
    assert((persons[2]).getFirstname() == "Micky");
    assert((persons[3]).getFirstname() == "Minnie");
    delete[] persons;
}

void testTemplateSortString(){
    int size = 4;
    std::string* strings = new std::string[size];
    strings[0] = "Minnie";
    strings[1] = "Daisy";
    strings[2] = "Donald";
    strings[3] = "Micky";
    sort(strings, size);
    assert((strings[0]) == "Daisy");
    assert((strings[1]) == "Donald");
    assert((strings[2]) == "Micky");
    assert((strings[3]) == "Minnie");
    delete[] strings;
}

void testTemplatePerson(){
    hfu::Person* persons = createArray();
    hfu::SimpleVector<hfu::Person> list(persons, 3);
    assert(list.getSize()==3);
    assert(list[2].getFirstname()=="Donald");
    assert(list[2].getLastname()=="Duck");
    list[2]=persons[3];
    assert(list[2].getFirstname()=="Micky");
    assert(list[2].getLastname()=="Maus");
    hfu::SimpleVector<hfu::Person> copy;
    assert(copy.getSize()==0);
    copy=list;
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    list[2]=persons[2];
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    copy=copy;
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    delete[] persons;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto PersonArray = createArray();
    sort(PersonArray, 4);
    //printArray(PersonArray, 4);
    testTemplateSortPerson();
    testTemplateSortString();
    //ANTWORT C:
    //WEIL der datentyp int keine methode compare hat
    testTemplatePerson();
    return 0;
}
