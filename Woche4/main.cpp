#include <iostream>
#include <cassert>

namespace hfu{
    class Person{
    private:
        std::string firstName;
        std::string lastName;

    public:
        Person(const std::string& firstName, const std::string& lastName): firstName(firstName), lastName(lastName){}
        std::string getFirstname(){
            return this->firstName;
        }
        std::string getLastname(){
            return this->lastName;
        }
        int compare(const Person& other){
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
    };
    class Movie{
    private:
        const std::string title;
        const std::string director;
        const int durationInMinutes;
    public:
        Movie(const std::string& title, const std::string& director, const int& duration) :
            title(title), director(director), durationInMinutes(duration){}
        std::string getTitle(){
            return this->title;
        }
        std::string getDirector(){
            return this->director;
        }
        int getDuration(){
            return this->durationInMinutes;
        }
    };
}
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
void test_movie(){

    std::string title = "Die nackte kanone";
    std::string director = "david zucker";
    int duration = 137;
    hfu::Movie movie1(title, director, duration);
    assert(movie1.getTitle() == title);
    assert(movie1.getDirector() == director);
    assert(movie1.getDuration() == duration);
}
void swap(hfu::Person* personen, int pos1, int pos2){
    std::cout << "Swapping..." << personen << " and " << personen+pos2 << std::endl;
    hfu::Person& toSafe = personen[pos1];
    personen[pos1] = personen[pos2];
    personen[pos2] = toSafe;
}
void swap2(hfu::Person* personen, int pos1, int pos2){

}
void sort(hfu::Person* personen, int size){
    hfu::Person* personenSorted;
    /*
    for(int i = 0; i < size-1; i++){
        if(personen[i].compare(personen[i+1]) > 0){
            std::cout << "Going to swap..." << std::endl;
            swap(personen, i, i+1);
            std::cout << "Swapped " << i << personen[i].getFirstname() <<  "and" << i+1 << personen[i+1].getFirstname() << std::endl;
        }
    }*/
    hfu::Person* end = personen + size;
    int counter = 0;
    for (hfu::Person *p = personen; p != end; ++p) {
        if(counter+1 < size)
            counter++;
        std::cout << counter << std::endl;
        std::cout << p->getFirstname() << std::endl;
        hfu::Person nextPerson = *(personen+counter);
        std::cout << "Current person: " << p->getFirstname() <<  std::endl << "Next Person:" << nextPerson.getFirstname() << std::endl;
        if(p->compare(nextPerson) < 0){
            swap(personen, counter -1, counter);
            std::cout << "Have to swap " << p->getFirstname() << " and " << nextPerson.getFirstname() << std::endl;
        }

    }
}

void test_sort(){
    hfu::Person p3("Donald", "Duck");
    hfu::Person p2("Daisy", "Duck");
    hfu::Person p1("Micky", "Maus");
    hfu::Person p4("Dagobert", "Duck");
    hfu::Person* personen = new hfu::Person[4]{p1, p2, p3, p4};
    personen[0] = p1;
    personen[1] = p2;
    personen[2] = p3;
    personen[3] = p4;
    sort(personen, 4);
    assert(personen[0].compare(p2) == 0);
    assert(personen[1].compare(p2) == 0);
    assert(personen[2].compare(p3) == 0);
    assert(personen[3].compare(p1) == 0);
}
int main() {
    std::cout << "Started..." << std::endl;
    test_person();
    test_movie();
    test_sort();
    std::cout << "Finished..." << std::endl;
    return 0;
}
