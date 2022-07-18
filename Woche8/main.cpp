#include <iostream>
#include <cassert>
#include "Movie.h"
#include <vector>
#include <unordered_map>

void testMovie(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    hfu::Movie scored_movie("Modern Times", director, 90, scores, 4);
    auto copy = hfu::Movie ("Modern Times", director, 90);
    copy=scored_movie;
    scored_movie.setScore(3,42);
    assert(copy.getScore(3) == 1);
}


std::vector<int> sum(const std::vector<int>& nums, int n){
    std::vector<int> result = {};
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            if(nums.at(i) + nums.at(j) == n){
                result = {i, j};
                return result;
            }

        }
    }
    return result;
}

std::vector<int> sumMap(const std::vector<int>& nums, int n){
    std::unordered_map<int, int> map;
    //copy vector to map
    for(int i = 0; i < nums.size(); i++){
        map[nums[i]] = i;
    }
    //check where sum happens
    //should be pretty fast, since index is stored in search trees and index is the value and key is the index
    for (auto& it: map) {
        int difference = n - it.first;
        int placeSecond = map[difference];
        if (placeSecond != 0){
            return {it.second, placeSecond};
        }
    }
}

void testNums(){
    std::vector<int> nums = {2,7,11,15};
    int n = 9;
    std::vector<int> expectedResult = {0,1};
    auto actualResult = sum(nums, n);
    assert(expectedResult.at(0) == actualResult.at(0));
    assert(expectedResult.at(1) == actualResult.at(1));
}

void testSumMap(){
    std::vector<int> nums = {2,7,11,15};
    int n = 9;
    std::vector<int> expectedResult = {0,1};
    auto actualResult = sumMap(nums, n);
    assert(expectedResult.at(0) == actualResult.at(0));
    assert(expectedResult.at(1) == actualResult.at(1));
}
int main() {
    std::cout << "Start Process..." << std::endl;
    testMovie();
    testNums();
    testSumMap();
    std::cout << "Finish Process..." << std::endl;
    return 0;
}
