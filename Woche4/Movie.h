//
// Created by Vincent on 21.04.2022.
//

#ifndef WOCHE4_MOVIE_H
#define WOCHE4_MOVIE_H
#include<string>
#include "Person.h"

namespace hfu{
    class Movie{
    private:
        const std::string title;
        const hfu::Person director;
        const int durationInMinutes;
        const int *scores;
        const int scoreCount;
        static int* copyArray(const int* originalArray, int length);
    public:
        Movie(const std::string& title, const hfu::Person& director, const int& duration) :
                Movie(title, director, duration, new int[0], 0){}
        Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int length) :
                title(title), director(director), durationInMinutes(duration), scores(copyArray(scores, length)), scoreCount(length){}
        std::string getTitle();
        hfu::Person getDirector();
        int getDuration();
        int getScoreCount();
        int getScore(int position);
    };
#endif //WOCHE4_MOVIE_H

}
