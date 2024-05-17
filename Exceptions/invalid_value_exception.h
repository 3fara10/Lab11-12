#pragma once
#include <stdexcept>

class InvalidValueException: public std::invalid_argument
{
private:
    char* message;
public:
    InvalidValueException(char* message):std::invalid_argument(message),message(message)
    {

    }
    char* what()
    {
        return message;
    }

};