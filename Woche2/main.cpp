#include <iostream>

/*
 * Helper für Conversion
 */
int strToInt(std::string text){
    int result = 0;
    int multiplicationFactor = 1;
    for(int i = text.size() -1; i >= 0; i--){
        int charAsNumber = text[i] - '0'; //convertiert den char in die entsprechende nummer, alternativ könnte man vom ascii wert den gewünschten wert abziehen
        result += charAsNumber * multiplicationFactor;
        multiplicationFactor*=10;
    }
    return result;
}

/*
 * Aufgabe 1
 */
int sum(std::string text){
    std::string delimiter = "+";
    int positionOfDelimiter = text.find("+");
    std::string firstNumberAsString = text.substr(0, positionOfDelimiter);
    //int firstNumber = std::stoi(firstNumberAsString);
    int firstNumber = strToInt(firstNumberAsString);
    std::string secondNumberAsString = text.substr(positionOfDelimiter+1, text.size());
    //int secondNumber = std::stoi(secondNumberAsString);
    int secondNumber = strToInt(secondNumberAsString);
    return firstNumber + secondNumber;
}


/*
 * Aufgabe 2
 */
int sum_reference(std::string& text){
    std::string delimiter = "+";
    int positionOfDelimiter = text.find("+");
    std::string firstNumberAsString = text.substr(0, positionOfDelimiter);
    int firstNumber = std::stoi(firstNumberAsString);
    std::string secondNumberAsString = text.substr(positionOfDelimiter+1, text.size());
    int secondNumber = std::stoi(secondNumberAsString);
    return firstNumber + secondNumber;
}

/*
 * Aufgabe 3
 */
int sum_pointer(std::string *text){
    std::string delimiter = "+";
    int positionOfDelimiter = text->find("+");
    std::string firstNumberAsString = text->substr(0, positionOfDelimiter);
    int firstNumber = std::stoi(firstNumberAsString);
    std::string secondNumberAsString = text->substr(positionOfDelimiter+1, text->size());
    int secondNumber = std::stoi(secondNumberAsString);
    return firstNumber + secondNumber;
}
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
/*
std::string encode_pointer(std::string* text){
    std::string result = "";
    int lowestAllowedAscii = int('A');
    int highestAllowedAscii = int('z');
    for(int i = 0; i < text->size(); i++){
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
*/
int main() {
    std::cout << "Start Program!" << std::endl;
    std::cout << sum("23+47") << std::endl;
    std::cout << "Finish Program!" << std::endl;
    return 0;
}
