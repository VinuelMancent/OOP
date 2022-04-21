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
        const hfu::Person director;
        const int durationInMinutes;
        const int *scores;
        const int scoreCount;
        static int* copyArray(const int* originalArray, int length){
            int* newArray = new int[length];
            for(int i = 0; i < length; i++){
                newArray[i] = originalArray[i];
            }
            return newArray;
        }
    public:
        Movie(const std::string& title, const hfu::Person& director, const int& duration) :
                Movie(title, director, duration, new int[0], 0){}
        Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int length) :
                title(title), director(director), durationInMinutes(duration), scores(copyArray(scores, length)), scoreCount(length){}
        std::string getTitle(){
            return this->title;
        }
        hfu::Person getDirector(){
            return this->director;
        }
        int getDuration(){
            return this->durationInMinutes;
        }
        int getScoreCount(){
            return this->scoreCount;
        }
        int getScore(int position){
            int score = this->scores[position];
            return score;
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

void sort(hfu::Person* personen, int size){
    for(int i = 0; i < size-1; i++){
        if(personen[i].compare(personen[i+1]) < 0){
            hfu::Person tempPerson = personen[i];
            personen[i] = personen[i+1];
            personen[i+1] = tempPerson;
        }
    }
}

void test_sort(){
    hfu::Person p1("Micky", "Maus");
    hfu::Person p2("Daisy", "Duck");
    hfu::Person p3("Donald", "Duck");
    hfu::Person p4("Dagobert", "Duck");
    hfu::Person* personen = new hfu::Person[4]{p1, p2, p3, p4};
    sort(personen, 4);
    assert(personen[0].compare(p1) == 0);
    assert(personen[1].compare(p3) == 0);
    assert(personen[2].compare(p2) == 0);
    assert(personen[3].compare(p4) == 0);
}
int main() {
    std::cout << "Started..." << std::endl;
    test_person();
    test_movie();
    test_movie2();
    test_sort();
    std::cout << "Finished..." << std::endl;
    return 0;
}
