//
// Created by Vincent on 21.04.2022.
//

#ifndef WOCHE5_MOVIE_H
#define WOCHE5_MOVIE_H
#include<string>
#include "Person.h"

namespace hfu{
    class Movie{
    private:
        const std::string title;
        const hfu::Person director;
        const int durationInMinutes;
        int *scores;
        const int scoreCount;
        static int* copyArray(const int* originalArray, int length);
    public:
        Movie(const std::string& title, const hfu::Person& director, const int& duration);
        Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int& length);
        Movie(const Movie& other);
        ~Movie();
        std::string getTitle();
        hfu::Person getDirector();
        int getDuration();
        int getScoreCount();
        int getScore(int position);
        void setScore(int score, int position);
    };
}
#endif //WOCHE5_MOVIE_H
