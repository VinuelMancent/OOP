//
// Created by Vincent on 21.04.2022.
//

#ifndef WOCHE8_MOVIE_H
#define WOCHE8_MOVIE_H
#include<string>
#include <vector>
#include "Person.h"

namespace hfu{
    class Movie{
    private:
        std::string title;
        hfu::Person director;
        int durationInMinutes;
        std::vector<int> scores;
        int scoreCount;
        static std::vector<int> copyArray(const int* originalArray, int length);
    public:
        Movie(const std::string& title, const hfu::Person& director, const int& duration);
        Movie(const std::string& title, const hfu::Person& director, const int& duration, const int* scores, const int& length);
        std::string getTitle();
        hfu::Person getDirector();
        int getDuration();
        int getScoreCount();
        int getScore(int position);
        void setScore(int score, int position);
        bool operator==(const Movie& other);
        bool operator!=(const Movie& other);
    };
}
#endif //WOCHE8_MOVIE_H
