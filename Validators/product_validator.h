#pragma once
#include "C:\Users\Home\CLionProjects\lab9-10\Exceptions\Invalid_code_exception.h"

class ProductValidator{
private:
public:
    ProductValidator(){
    }

    template<typename T>
    void verifyInt(const T& value) {
        if (!std::is_same<T, int>::value) {
            throw InvalidValueException("The provided value is not an int.");
        }
    }
};