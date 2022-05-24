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
public:
    WordSequence(std::string* words, int size);
    WordSequence();
    WordSequence(const WordSequence& other);
    ~WordSequence();
    std::string& GetWordAtPosition(int position);
    int getSize();
    friend std::ostream& operator<<(std::ostream& os, const WordSequence& sequence);
    WordSequence& operator=(const WordSequence& other);
    std::string& operator[](int);
    std::string operator[](int) const;
};


#endif //WOCHE6_WORDSEQUENCE_H
