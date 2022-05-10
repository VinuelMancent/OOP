//
// Created by Vincent on 03.05.2022.
//


#include <iostream>
#include "WordSequence.h"

WordSequence::WordSequence(std::string* words,int size): words(words), size(size){}
WordSequence::WordSequence() : WordSequence(new std::string[0], 0){}
WordSequence::WordSequence(const WordSequence& other) :
        words(copyArray(other.words, size)), size(other.size){
    std::cout << "copy" << std::endl;
}
WordSequence::~WordSequence(){
    delete WordSequence::words;
}
std::string& WordSequence::GetWordAtPosition(int position){
    if(position >= size || position < 0){
        throw std::invalid_argument("position out of array range");
    }
    return words[position];
}

std::string* WordSequence::copyArray(const std::string* originalArray, int length){
    std::string* newArray = new std::string[length];
    for(int i = 0; i < length; i++){
        newArray[i] = originalArray[i];
    }
    std::cout << "copying array" << std::endl;
    return newArray;
}

