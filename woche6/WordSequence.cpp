//
// Created by Vincent on 03.05.2022.
//

#include "WordSequence.h"
#include <iostream>

namespace hfu{
    class WordSequence{
    private:
        std::string* words;
        int size;
        static std::string* copyArray(const std::string* originalArray, int length){
            std::string* newArray = new std::string[length];
            for(int i = 0; i < length; i++){
                newArray[i] = originalArray[i];
            }
            return newArray;
        }
    public:
        WordSequence(std::string* words, int size) : words(words), size(size){}
        WordSequence() : WordSequence(new std::string[0], 0){}
        WordSequence(const hfu::WordSequence& other) :
            words(copyArray(other.words, size)), size(other.size){}
        /*~WordSequence(){
            delete words;
        }*/
        int getSize(){
            return size;
        }
        std::string& GetWordAtPosition(int position){
            if(position >= size || position < 0){
                throw std::invalid_argument("position out of array range");
            }
            return words[position];
        }
    };
}
