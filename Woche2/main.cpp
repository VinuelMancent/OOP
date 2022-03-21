#include <iostream>

/*
 * Aufgabe 1
 */


/*
 * Aufgabe 4
 */
std::string encode(std::string text){
    std::string result = "";
    int lowestAllowedAscii = int('A');
    int highestAllowedAscii = int('z');
    for(int i = 0; i < text.size(); i++){
        if(int(text[i]) < lowestAllowedAscii || int(text[i]) > highestAllowedAscii)
            throw std::invalid_argument("Your input is only allowed to contain letters");
        else if(text[i] == 'z')
            result += 'a';
        else if(text[i] == 'Z')
            result += 'A';
        else
            result+= text[i]+1;
    }
    return result;
}

/*
 * Aufgabe 5
 */
std::string encode_reference(std::string& text){
    std::string result = "";
    int lowestAllowedAscii = int('A');
    int highestAllowedAscii = int('z');
    for(int i = 0; i < text.size(); i++){
        if(int(text[i]) < lowestAllowedAscii || int(text[i]) > highestAllowedAscii)
            throw std::invalid_argument("Your input is only allowed to contain letters");
        else if(text[i] == 'z')
            result += 'a';
        else if(text[i] == 'Z')
            result += 'A';
        else
            result+= text[i]+1;
    }
    return result;
}

/*
 * Aufgabe 6
 */
std::string encode_pointer(std::string* text){
    std::string result = "";
    int lowestAllowedAscii = int('A');
    int highestAllowedAscii = int('z');
    for(int i = 0; i < text.size(); i++){
        if(int(text[i]) < lowestAllowedAscii || int(text[i]) > highestAllowedAscii)
            throw std::invalid_argument("Your input is only allowed to contain letters");
        else if(text[i] == 'z')
            result += 'a';
        else if(text[i] == 'Z')
            result += 'A';
        else
            result+= text[i]+1;
    }
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
