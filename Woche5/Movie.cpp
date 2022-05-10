//
// Created by Vincent on 27.04.2022.
//
#include <iostream>
#include "Person.h"
#include "Movie.h"




int* hfu::Movie::copyArray(const int* originalArray, int length){
    int* newArray = new int[length];
    for(int i = 0; i < length; i++){
        newArray[i] = originalArray[i];
    }
    return newArray;
}

hfu::Movie::Movie(const std::string& title, const hfu::Person& director, const int& duration) :
        Movie(title, director, duration, new int[0], 0){}
hfu::Movie::Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int& length) :
        title(title), director(director), durationInMinutes(duration), scores(copyArray(scores, length)), scoreCount(length){}
//Muss noch angepasst werden, so dass ein neuer array erstellt wird für die scores
hfu::Movie::Movie(const Movie& other): Movie(other.title, other.director, other.durationInMinutes, copyArray(other.scores, other.scoreCount), other.scoreCount){}
hfu::Movie::~Movie(){
    delete scores;
}
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


