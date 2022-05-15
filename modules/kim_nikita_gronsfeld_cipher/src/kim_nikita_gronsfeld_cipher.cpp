// Copyright 2022 Kim Nikita

#include <string>
#include <vector>
#include <map>

#include "include/kim_nikita_gronsfeld_cipher.h"

int GronsfeldCipher::mod(int start, int end, int result) const {
  int difference = end - start;
  int result_from_start = result - start;
  int res = start + result_from_start % difference;
  while (res < start) {
    res += difference;
  }
  return res;
}

double GronsfeldCipher::transvection(std::map<char, int> frequencies,
  double probability[], int d, int sub_size) const {
  double prob = 0;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    double freq = frequencies[ch] * 1.0 / sub_size;
    int index = mod(0, 26, ch - 'A' - d);
    prob += freq * probability[index];
  }
  return prob;
}

GronsfeldCipher::GronsfeldCipher() {
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 26; j++) {
      table[i][j] = alpha[(j + i) % 26];
    }
  }
}

std::string GronsfeldCipher::getGronsfeldTable() {
  std::string gronsfeld_table = "";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 26; j++) {
      gronsfeld_table += table[i][j];
    }
    gronsfeld_table += '\n';
  }
  return gronsfeld_table;
}

std::string GronsfeldCipher::encode(const std::string& source_text,
    const std::string& key) const {
  std::string ciphered_text = "";
  std::string period_key = "";

  int size = source_text.size();
  int period = key.size();

  for (int i = 0; i < size; i++) {
    period_key += key[i % period];
  }

  for (int i = 0; i < size; i++) {
    ciphered_text += table[period_key[i] - '0'][source_text[i] - 'A'];
  }

  return ciphered_text;
}

std::string GronsfeldCipher::decode(const std::string& ciphered_text,
    const std::string& key) const {
  std::string source_text = "";
  std::string period_key = "";

  int size = ciphered_text.size();
  int period = key.size();

  for (int i = 0; i < size; i++) {
    period_key += key[i % period];
  }

  for (int i = 0; i < size; i++) {
    int j = 0;
    int k = period_key[i] - '0';
    while (table[k][j] != ciphered_text[i]) {
      j++;
    }
    source_text += table[0][j];
  }

  return source_text;
}

std::string GronsfeldCipher::hack(const std::string& ciphered_text,
    int key_length) const {
  // Table of frequency distribution of letters of the English alphabet
  double probability[] = { 0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.02,
    0.061, 0.07, 0.002, 0.008, 0.04, 0.024, 0.067, 0.075, 0.019, 0.001, 0.06,
    0.063, 0.091, 0.028, 0.01, 0.023, 0.001, 0.02, 0.001 };

  std::string key = "";
  int text_size = ciphered_text.size();
  std::vector<std::string> groups;

  // Divide the text into groups of characters corresponding
  // to the i character of the key
  for (int i = 0; i < key_length; i++) {
    std::string temp_str = "";
    for (int j = 0; i + j * key_length < text_size; j++) {
      temp_str += ciphered_text[i + j * key_length];
    }
    groups.push_back(temp_str);
  }

  // Generate key
  for (int i = 0; i < key_length; i++) {
    double max_prob = 0;
    char key_piece;
    std::string sub_cipher = groups[i];
    int sub_size = sub_cipher.size();
    std::map<char, int> frequencies;

    // Counting the frequencies of letters in a group
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      frequencies[ch] = 0;
    }
    for (int i = 0; i < sub_size; i++) {
      frequencies[sub_cipher[i]]++;
    }

    // For each digit determine the probability of its occurrence
    // at the i position of the key
    for (int d = 0; d < 10; d++) {
      double prob = transvection(frequencies, probability, d, sub_size);
      if (prob >= max_prob) {
        max_prob = prob;
        key_piece = d + '0';
      }
    }
    key += key_piece;
  }

  return key;
}
