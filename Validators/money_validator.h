#pragma once
#include <vector>

#include "C:\Users\Home\CLionProjects\lab9-10\Exceptions\invalid_value_exception.h"
class MoneyValidator{
private:
    std::vector<double>values;

public:
    MoneyValidator(){
        values={0.1,0.5,1,5,10,20,50,100,200,500};
    }

    void validate(double value){
        int i=0;
        while(values[i]!=value && i<10){
            i++;
        }
        if(i>=10)
        {
            throw InvalidValueException("The given code must be natural number");
        }
    }
};
