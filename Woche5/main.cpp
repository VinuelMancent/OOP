#include <iostream>
#include <cassert>

namespace hfu{
    class Person{
    private:
        std::string firstName;
        std::string lastName;

    public:
        Person(const std::string& firstName, const std::string& lastName): firstName(firstName), lastName(lastName){}
        Person(const Person& other): Person(other.firstName, other.lastName){};

        std::string getFirstname(){
            return this->firstName;
        }
        std::string getLastname(){
            return this->lastName;
        }
        void setFirstName(std::string firstName){
            this->firstName = firstName;
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
        int *scores;
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
        //Muss noch angepasst werden, so dass ein neuer array erstellt wird für die scores
        Movie(const Movie& other): Movie(other.title, other.director, other.durationInMinutes, copyArray(other.scores, other.scoreCount), other.scoreCount){}
        ~Movie(){
            delete scores;
        }
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
        void setScore(int position, int score){
            if(score<0){
                throw std::invalid_argument("score can't be negative!");
            }
            if(position >= scoreCount || position < 0){
                throw std::invalid_argument("position has to be between 0 and " + scoreCount -1);
            }
            this->scores[position] = score;
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
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size - i; j++){
            if(personen[i].compare(personen[i+1]) > 0) {
                hfu::Person tempPerson = personen[j];
                personen[j] = personen[j + 1];
                personen[j + 1] = tempPerson;
            }
        }
    }
}
void printArray(hfu::Person* personen, int size){
    for(int i = 0; i < size; i++){
        std::cout << personen[i].getFirstname() << std::endl;
    }
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
    test_person();
    test_person2();
    test_movie();
    test_movie2();
    test_movie3();
    test_movie_setScore();
    test_sort();
    std::cout << "Finished..." << std::endl;
    return 0;
}
