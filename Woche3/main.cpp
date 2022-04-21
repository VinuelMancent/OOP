#include <iostream>
#include <cassert>

namespace hfu{
    class Person{
    private:
        std::string firstName;
        std::string lastName;
        int compareStrings(std::string name1, std::string name2){
            if(name1 < name2)
                return -1;
            else if(name1 > name2)
                return 1;
            else
                return 0;
        }
        
    public:
        void setFirstname(const std::string& firstName){
            this->firstName = firstName;
        }
        void setLastname(const std::string& lastName){
            this->lastName = lastName;
        }
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
        std::string title;
        std::string director;
        int durationInMinutes;
    public:
        void setTitle(std::string& title){
            this->title = title;
        }
        void setDirector(std::string& director){
            this->director = director;
        }
        void setDuration(int& duration){
            this->durationInMinutes = duration;
        }
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
    hfu::Person person;
    std::string donald="Donald";
    person.setFirstname(donald);
    assert(person.getFirstname()=="Donald");
    donald[0]='X';
    assert(person.getFirstname()=="Donald");
    std::string duck="Duck";
    person.setLastname(duck);
    assert(person.getLastname()=="Duck");
    duck[0]='X';
    assert(person.getLastname()=="Duck");
    hfu::Person person2;
    std::string daisy = "Daisy";
    person2.setFirstname(daisy);
    person2.setLastname(duck);
    person.compare(person2);
}
void test_movie(){
    hfu::Movie movie1;
    std::string title = "Die nackte kanone";
    std::string director = "david zucker";
    int duration = 137;
    movie1.setTitle(title);
    movie1.setDirector(director);
    movie1.setDuration(duration);
    assert(movie1.getTitle() == title);
    assert(movie1.getDirector() == director);
    assert(movie1.getDuration() == duration);
}
int main() {
    std::cout << "Started..." << std::endl;
    test_person();
    test_movie();
    std::cout << "Finished..." << std::endl;
    return 0;
}
