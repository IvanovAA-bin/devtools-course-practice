// Copyright 2022 Ivanov Arkady

#include <sstream>
#include <string>

#include "include/kim_nikita_gronsfeld_cipher.h"
#include "include/gronsfeld_app.h"


std::string GronsfeldApp::operator()(int argc, const char** argv) const {
    std::stringstream out;
    GronsfeldCipher gc;

    if (argc <= 1) {
        out << "This is a Gronsfeld cipher application.\n";
        out << "Type -help to get additional information";
        return out.str();
    }

    if (argc == 2) {
        std::string command(argv[1]);
        if (command == "-help") {
            out << "Use following format to use application:\n";
            out << "COMMAND | STRING\n";
            out << "Where COMMAND can be: encode, decode, hack\n";
            out << "STRING is a non empty string\n";
            out << "encode, decode commands has 2 arguments:"
                " input string and key\n";
            out << "hack command has 2 arguments: input string and key length";

            return out.str();
        } else {
            out << "Wrong format of command";
            return out.str();
        }
    }

    if (argc == 3 || argc >= 5) {
        out << "Wrong number of arguments";
        return out.str();
    }

    std::string operation(argv[1]);
    std::string inStr(argv[2]);
    std::string key(argv[3]);

    if (operation == "encode") {
        out << gc.encode(inStr, key);
    } else if (operation == "decode") {
        out << gc.decode(inStr, key);
    } else if (operation == "hack") {
        try {
            int keyLength = std::stoi(key);
            out << gc.hack(inStr, keyLength);
        } catch (std::invalid_argument& ex) {
            out << "Wrong key format";
        }
    } else {
        out << "Wrong operation type";
    }
    return out.str();
}
