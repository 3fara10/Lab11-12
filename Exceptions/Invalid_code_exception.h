#pragma once
#include <stdexcept>

class InvalidCodeException :public std::invalid_argument{
private:
    char* message;
public:
    InvalidCodeException(char* message):
            std::invalid_argument(message), message(message){
    }
    char* what(){
        return message;
    }

};
