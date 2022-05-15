// Copyright 2022 Kim Nikita

#ifndef MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
#define MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_

#include <string>
#include <map>

class GronsfeldCipher {
 private:
    char table[10][26];
    int mod(int start, int end, int result) const;
    double transvection(std::map<char, int> frequencies, double probability[],
      int d, int sub_size) const;
 public:
    GronsfeldCipher();
    std::string getGronsfeldTable();
    std::string encode(const std::string& source_text,
        const std::string& key) const;
    std::string decode(const std::string& ciphered_text,
        const std::string& key) const;
    std::string hack(const std::string& ciphered_text, int key_length) const;
};

#endif  // MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
