//
// Created by Vincent on 03.05.2022.
//


#include <iostream>
#include "WordSequence.h"

WordSequence::WordSequence(std::string* words,int size): words(copyArray(words, size)), size(copySize(size)){
    std::cout << "ctor with parameters" << std::endl;
}
WordSequence::WordSequence() : WordSequence(new std::string[0], 0){
    std::cout << "ctor without parameters" << std::endl;
}
WordSequence::WordSequence(const WordSequence& other) :
        words(copyArray(other.words, size)), size(other.size){
    std::cout << "copy" << std::endl;
}
WordSequence::~WordSequence(){
    delete[] words;
}
std::string& WordSequence::GetWordAtPosition(int position){
    if(position >= size || position < 0){
        throw std::invalid_argument("position out of array range");
    }
    return words[position];
}

int WordSequence::getSize() {
    return this->size;
}
std::string WordSequence::word(int position){
    if(position < 0 || position >= size){
        throw std::invalid_argument("position needs to be in range");
    }
    return words[position];
}

void WordSequence::word(int position, std::string& word){
    words[position] = word;
}
std::string* WordSequence::copyArray(const std::string* originalArray, int length){
    std::string* newArray = new std::string[length];
    for(int i = 0; i < length; i++){
        newArray[i] = originalArray[i];
    }
    std::cout << "copying array" << std::endl;
    return newArray;
}

int WordSequence::copySize(int size){
    if(size < 0){
        throw std::invalid_argument("size can't be negative");
    }
}

