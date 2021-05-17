#include "../inc/PESEL.hpp"
#include <vector>
#include <iostream>

void PESEL::show() {
    std::cout << "PESEL number: " << full_ << '\n';
    std::cout << "Brithdate: " << full_[4] << full_[5] << '.' <<
                                    month() << '.' << year() << '\n';
    std::cout << "Sex: " << sex() << '\n';
    std::string validate = isValid() ? "Yes" : "No";
    std::cout << "Is Valid: " << validate << '\n';
}
std::string PESEL::year() {
    std::string ret;
    switch(full_[2]) {
        case '0':
            ret.push_back('1');
            ret.push_back('9');
            break;
        case '1':
            ret.push_back('1');
            ret.push_back('9');
            break;
        case '2':
            ret.push_back('2');
            ret.push_back('0');
            break;
        case '3':
            ret.push_back('2');
            ret.push_back('0');
            break;
        case '4':
            ret.push_back('2');
            ret.push_back('1');
            break;
        case '5':
            ret.push_back('2');
            ret.push_back('1');
            break;
        case '6':
            ret.push_back('2');
            ret.push_back('2');
            break;
        case '7':
            ret.push_back('2');
            ret.push_back('2');
            break;
        case '8':
            ret.push_back('1');
            ret.push_back('8');
            break;
        case '9':
            ret.push_back('1');
            ret.push_back('8');
            break;
    }
    ret.push_back(full_[0]);
    ret.push_back(full_[1]);
    
    return ret;
}
std::string PESEL::month() {
    std::string ret;
    if(full_[2] % 2 == 0)
        ret.push_back('0');
    else
        ret.push_back('1');

    ret.push_back(full_[3]);

    return ret;
}
bool PESEL::isValid() {
    std::vector<int> vec;
    int sum{};
    for(auto el : full_)
        vec.push_back(el - 48);
    vec.pop_back();
    for(int i = 0; i <= 9; i++) {
        if(i == 1 || i == 5 || i == 9)
            vec[i] *= 3;
        else if(i == 2 || i == 6)
            vec[i] *= 7;
        else if(i == 3 || i == 7)
            vec[i] *= 9;
    }
    for(auto& el : vec) {
        while(el > 9)
            el -= 10;
        sum += el;
    }
    while(sum > 9)
        sum -= 10;
    return ((10 - sum) == (full_[10] - 48));
}
