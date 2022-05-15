// Copyright 2022 Ivanov Arkady

#include <iostream>
#include <string>

#include "include/gronsfeld_app.h"
#include "include/kim_nikita_gronsfeld_cipher.h"

int main(int argc, const char** argv) {
    GronsfeldApp app;
    std::string out = app(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
