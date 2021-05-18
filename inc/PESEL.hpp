#pragma once

#include <string>

class PESEL {
public:
    PESEL(){}
    PESEL(std::string full) :
        full_(full){}

    void show();

private:
    std::string full_;

    char sex(){ return full_[9] % 2 == 1 ? 'M' : 'K'; }
    bool isValid();
    std::string year();
    std::string month();
};
