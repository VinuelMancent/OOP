#include <iostream>
#include <cassert>
#include "WordSequence.h"

void testWordSequenceCtor(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    std::cout << "finished test 1" << std::endl;
}

void testWordSequenceGetWordAtPosition(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    assert(sequence.GetWordAtPosition(0)== "lore");

    try{
        sequence.GetWordAtPosition(-1);
        assert(false);
    } catch(...){

    }
    try{
        sequence.GetWordAtPosition(3);
        assert(false);
    } catch(...){

    }
}
void testWordSequenceCopyCtor(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    words[0]="foo";
    std::cout << sequence.GetWordAtPosition(0) << std::endl;
    assert(sequence.GetWordAtPosition(0)== "lore");
}
void testWord(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    assert(sequence[0]== "lore");
}
void testCtorFaulty(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    try{
        WordSequence sequence(words, -1);
        assert(false);
    }catch(...){
        assert(true);
    }
}
void testWordFaulty(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    try{
        sequence[-1];
        assert(false);
    } catch(...){

    }
    try{
        sequence[4];
        assert(false);
    } catch(...){

    }
    assert(true);
}

void testWordSequence2(){
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    words[0]="foo";
    assert(sequence[0]== "lore");
}

std::ostream& operator<<(std::ostream& os, const WordSequence& sequence){
    std::cout << "(";
    for(int i = 0; i < sequence.size; ++i){
        std::cout << sequence.words[i];
        if(i < sequence.size -1)
            std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}
int main() {
    std::cout << "Start programm..." << std::endl;
    testWordSequenceCtor();
    testWordSequenceGetWordAtPosition();
    testWordSequenceCopyCtor();
    testWord();
    testCtorFaulty();
    testWordFaulty();
    testWordSequence2();
    std::string words[3]={"lore", "ipsum", "dolor"};
    WordSequence sequence(words, 3);
    WordSequence sequence2;
    std::cout << "declaring sequence2 as sequence" << std::endl;
    sequence2 = sequence;
    std::cout << sequence << std::endl;
    std::cout << sequence2 << std::endl;
    std::cout << "Finish programm..." << std::endl;
    return 0;
}
