//
// Created by Vincent on 27.04.2022.
//
#include <iostream>
#include "Person.h"
#include "Movie.h"




std::vector<int> hfu::Movie::copyArray(const int* originalArray, int length){
    std::vector<int> newVector = std::vector<int>(length);
    for(int i = 0; i < length; i++){
        newVector[i] = originalArray[i];
    }
    return newVector;
}

hfu::Movie::Movie(const std::string& title, const hfu::Person& director, const int& duration) :
        Movie(title, director, duration, new int[0], 0){}
hfu::Movie::Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int& length) :
        title(title), director(director), durationInMinutes(duration), scores(copyArray(scores, length)), scoreCount(length){}

std::string hfu::Movie::getTitle(){
    return this->title;
}
hfu::Person hfu::Movie::getDirector(){
    return this->director;
}
int hfu::Movie::getDuration(){
    return this->durationInMinutes;
}
int hfu::Movie::getScoreCount(){
    return this->scoreCount;
}
int hfu::Movie::getScore(int position){
    int score = this->scores[position];
    return score;
}
void hfu::Movie::setScore(int position, int score){
    if(score<0){
        throw std::invalid_argument("score can't be negative!");
    }
    if(position >= scoreCount || position < 0){
        throw std::invalid_argument("position has to be between 0 and " + scoreCount -1);
    }
    this->scores[position] = score;
}

bool hfu::Movie::operator==(const hfu::Movie& other){
    if(this->title != other.title
    || this->scoreCount != other.scoreCount
    || this->scores != other.scores
    || this->durationInMinutes != other.durationInMinutes
    || this->director.compare(other.director) != 0){
        return false;
    }
    return true;
}

bool hfu::Movie::operator!=(const hfu::Movie& other){
    return !operator==(other);
}


