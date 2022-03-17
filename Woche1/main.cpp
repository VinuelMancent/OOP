#include <iostream>
#include <cassert>

int sum(std::string text){
    std::string delimiter = "+";
    int positionOfDelimiter = text.find("+");
    std::string firstNumberAsString = text.substr(0, positionOfDelimiter);
    int firstNumber = std::stoi(firstNumberAsString);
    std::string secondNumberAsString = text.substr(positionOfDelimiter+1, text.size());
    int secondNumber = std::stoi(secondNumberAsString);
    return firstNumber + secondNumber;
}

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

void test_encode() {
    std::string text = "Zyklotrop";
    auto actual = encode(text);
    std::string expected = "Azlmpuspq";
    assert(expected == actual);
    text = "H2o";
    try{
        actual = encode(text);
        assert(false);
    } catch (...) {
    }
}

int main() {
    std::cout << "Starting..." << std::endl;
    std::cout << encode("test") << std::endl;
    test_encode();
    std::cout << sum("23+47") << std::endl;
    std::cout << "Finishing..." << std::endl;
    return 0;
}


