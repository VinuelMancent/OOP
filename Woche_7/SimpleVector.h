//
// Created by Vincent on 24.05.2022.
//

#ifndef WOCHE_7_SIMPLEVECTOR_H
#define WOCHE_7_SIMPLEVECTOR_H

#include <iostream>
namespace hfu {


    template<class T>
    class SimpleVector {
    private:

        T *content;
        int size;

        T *copyArray(const T *originalArray, int length) {
            T *newArray = new T[length];
            for (int i = 0; i < length; i++) {
                newArray[i] = originalArray[i];
            }
            return newArray;
        }

    public:
        SimpleVector(T *content, int size) : content(copyArray(content, size)), size(size) {}

        SimpleVector() : SimpleVector(new T[0], 0) {}

//Konstruktorverkettung
        SimpleVector(const SimpleVector &other) : SimpleVector(other.content, other.size) {};

        ~SimpleVector() {
            delete[] content;
        }
        int getSize() {
            return this->size;
        }

//Muster im Skript -->
        SimpleVector &operator=(const SimpleVector &other) {
            if (this == &other)
                return *this;
            delete[] content;
            content = copyArray(other.content, other.size);
            size = other.size;
            return *this;
        }


        T &operator[](int index) {
            if (index >= this->size || index < 0) {
                throw std::invalid_argument("index out of bounds");
            }
            return content[index];
        }

        T operator[](int index) const {
            if (index >= this->size || index < 0) {
                throw std::invalid_argument("index out of bounds");
            }
            return content[index];
        }
    };

}
#endif //WOCHE_7_SIMPLEVECTOR_H
