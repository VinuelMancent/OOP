//
// Created by Vincent on 27.04.2022.
//

#include <iostream>
#include <cassert>
#include "Movie.h"
#include "Person.h"

void test_person(){
    hfu::Person person("Donald", "Duck");
    assert(person.getFirstname()=="Donald");
    assert(person.getFirstname()=="Donald");
    assert(person.getLastname()=="Duck");
    assert(person.getLastname()=="Duck");
    hfu::Person person2("Daisy", "Duck");
    std::string daisy = "Daisy";
    person.compare(person2);
}

void test_person2(){
    hfu::Person person1("Vincent", "Mattes");
    hfu::Person personCopy = person1;
    personCopy.setFirstName("Donald");
    assert(person1.getFirstname() == "Vincent");
}

void test_movie(){

    std::string title = "Die nackte kanone";
    hfu::Person director("David", "Zucker");
    int duration = 137;
    hfu::Movie movie1(title, director, duration);
    assert(movie1.getTitle() == title);
    assert(movie1.getDirector().compare(director) == 0);
    assert(movie1.getDuration() == duration);
}

void test_movie2(){
    hfu::Person director("Donald", "Duck");
    int scores[]={4,7,1,1};
    hfu::Movie scored_movie("Modern Times", director,90, scores,4);
    scores[3]=23;
    assert(scored_movie.getScoreCount()==4);
    assert(scored_movie.getScore(0)==4);
    assert(scored_movie.getScore(1)==7);
    assert(scored_movie.getScore(2)==1);
    assert(scored_movie.getScore(3)==1);
}

void test_movie3(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    hfu::Movie scored_movie("Modern Times", director, 90, scores, 4);
    auto copy=scored_movie;
    scored_movie.setScore(3,42);
    assert(copy.getScore(3) == 1);
}

void test_movie_setScore(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    hfu::Movie scored_movie("Modern Times", director, 90, scores, 4);
    scored_movie.setScore(3,42);
    assert(scored_movie.getScore(3) == 42);
    try{
        scored_movie.setScore(0, -2);
        assert(false);
    } catch(...){

    }
    try{
        scored_movie.setScore(-1, 4);
        assert(false);
    }catch(...){

    }
    try{
        scored_movie.setScore(17, 4);
        assert(false);
    }catch(...){

    }
}
void sort(hfu::Person* personen, int size){
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(personen[i].compare(personen[j]) > 0) {
                hfu::Person tempPerson = personen[j];
                personen[j] = personen[i];
                personen[i] = tempPerson;
            }
        }
    }
}
void printArray(hfu::Person* personen, int size){
    for(int i = 0; i < size; i++){
        std::cout << personen[i].getFirstname() << std::endl;
    }
}
hfu::Person* createArray() {
    hfu::Person* result = new hfu::Person[4];
    result[0]=hfu::Person("Minnie", "Maus");
    result[1]=hfu::Person("Daisy", "Duck");
    result[2]=hfu::Person("Donald", "Duck");
    result[3]=hfu::Person("Micky", "Maus");
    return result;
}

void testTemplateSort(){
    int size = 4;
    hfu::Person* persons = createArray();
    //printArray(persons, 4);
    sort(persons, size);
    printArray(persons, 4);
    assert((persons[0]).getFirstname() == "Daisy");
    assert((persons[1]).getFirstname() == "Donald");
    assert((persons[2]).getFirstname() == "Micky");
    assert((persons[3]).getFirstname() == "Minnie");
    delete[] persons;
}


void test_sort(){
    hfu::Person p1("Micky", "Maus");
    hfu::Person p2("Daisy", "Duck");
    hfu::Person p3("Donald", "Duck");
    hfu::Person p4("Dagobert", "Duck");
    hfu::Person* personen = new hfu::Person[4]{p4, p2, p3, p1};
    sort(personen, 4);
    printArray(personen, 4);
    assert(personen[0].compare(p4) == 0);
    assert(personen[1].compare(p2) == 0);
    assert(personen[2].compare(p3) == 0);
    assert(personen[3].compare(p1) == 0);
}
int main() {
    std::cout << "Started..." << std::endl;
    testTemplateSort();
    std::cout << "Finished..." << std::endl;
    return 0;
}
