//
// Created by Vincent on 03.05.2022.
//

#ifndef WOCHE6_WORDSEQUENCE_H
#define WOCHE6_WORDSEQUENCE_H


class WordSequence {
private:

    std::string* words;
    int size;
    std::string* copyArray(const std::string* originalArray, int length);
    int copySize(int size);
public:
    WordSequence(std::string* words, int size);
    WordSequence();
    WordSequence(const WordSequence& other);
    ~WordSequence();
    std::string& GetWordAtPosition(int position);
    int getSize();
    std::string word(int position);
    void word(int position, std::string& word)
};


#endif //WOCHE6_WORDSEQUENCE_H
