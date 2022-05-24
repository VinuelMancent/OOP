//
// Created by Vincent on 24.05.2022.
//

#include <iostream>
#include "SimpleVector.h"


SimpleVector::SimpleVector(T* words,int size): words(copyArray(words, size)), size(size){}
SimpleVector::SimpleVector() : WordSequence(new std::string[0], 0){}
//Konstruktorverkettung
WordSequence::WordSequence(const WordSequence& other) : WordSequence(words, size){};
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

//Muster im Skript -->
WordSequence& WordSequence::operator=(const WordSequence& other){
    if(this==&other)
        return *this;
    delete[] words;
    words = copyArray(other.words, other.size);
    size = other.size;
    return *this;
}


std::string* WordSequence::copyArray(const std::string* originalArray, int length){
    std::string* newArray = new std::string[length];
    for(int i = 0; i < length; i++){
        newArray[i] = originalArray[i];
    }
    return newArray;
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