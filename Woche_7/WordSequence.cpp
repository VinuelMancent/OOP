//
// Created by Vincent on 03.05.2022.
//


#include <iostream>
#include "WordSequence.h"

WordSequence::WordSequence(std::string* words,int size): words(copyArray(words, size)), size(copySize(size)){}
WordSequence::WordSequence() : WordSequence(new std::string[0], 0){}
WordSequence::WordSequence(const WordSequence& other) :
        words(copyArray(other.words, other.size)), size(other.size){}
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

WordSequence& WordSequence::operator=(const WordSequence& other){
    this->words = copyArray(other.words, other.size);
    this->size = other.size;
}


std::string* WordSequence::copyArray(const std::string* originalArray, int length){
    std::string* newArray = new std::string[length];
    for(int i = 0; i < length; i++){
        newArray[i] = originalArray[i];
    }
    return newArray;
}

int WordSequence::copySize(int size){
    if(size < 0){
        throw std::invalid_argument("size can't be negative");
    }
}

std::string& WordSequence::operator[](int index){
    if( index >= this->size || index < 0){
        throw std::invalid_argument("index out of bounds");
    }
    return words[index];
}

std::string WordSequence::operator[](int index) const{
    if( index >= this->size || index < 0){
        throw std::invalid_argument("index out of bounds");
    }
    return words[index];
}


