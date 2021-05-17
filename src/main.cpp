#include "../inc/PESEL.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string* check = new std::string(argv[1]);
    if(argc != 2) {
        std::cerr << "Invalid number of arguments.\n" <<
                        "Usage: ./PESEL <PESEL>\n";
        delete check;
        return 1;
    } else if(check->length() != 11) {
        std::cerr << "Invalid PESEL length.\n" <<
                        "Usage: ./PESEL <PESEL>\n";
        delete check;
        return 1;
    }
    delete check;

    PESEL pesel = PESEL(argv[1]);
    pesel.show();
    return 0;
}
