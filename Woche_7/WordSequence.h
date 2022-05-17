//
// Created by Vincent on 03.05.2022.
//

#ifndef WOCHE7_WORDSEQUENCE_H
#define WOCHE7_WORDSEQUENCE_H


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
    friend std::ostream& operator<<(std::ostream& os, const WordSequence& sequence);
    WordSequence& operator=(const WordSequence& other);
    std::string& operator[](int);
    std::string operator[](int) const;
};


#endif //WOCHE7_WORDSEQUENCE_H
