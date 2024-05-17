#pragma once
#include<stdexcept>
class NotFoundException:public std::runtime_error
{
private:
    char* message;
public:
    NotFoundException(char* message):std::runtime_error(message),message(message)
    {

    }
    char* what()
    {
        return message;
    }
};