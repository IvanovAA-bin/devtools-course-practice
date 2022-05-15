// Copyright 2022 Ivanov Arkady

#ifndef MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_APP_H_
#define MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_APP_H_

#include <string>

class GronsfeldApp {
 public:
     std::string operator()(int argc, const char** argv) const;
};

#endif  // MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_APP_H_
