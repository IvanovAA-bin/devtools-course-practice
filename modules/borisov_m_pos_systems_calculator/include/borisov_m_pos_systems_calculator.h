// Copyright 2022 Borisov Maxim

#ifndef MODULES_BORISOV_M_POS_SYSTEMS_CALCULATOR_INCLUDE_BORISOV_M_POS_SYSTEMS_CALCULATOR_H_
#define MODULES_BORISOV_M_POS_SYSTEMS_CALCULATOR_INCLUDE_BORISOV_M_POS_SYSTEMS_CALCULATOR_H_

#include <string>

class converter {
  converter() = delete;
  converter& operator=(const converter& convert) = delete;

 public:
  static int convert(const std::string& num);

 private:
  static int convert_hex(const std::string& num);
  static int convert_bin(const std::string& num);
  static int convert_oct(const std::string& num);
  static bool is_hex(const std::string& num);
  static bool is_bin(const std::string& num);
  static bool is_oct(const std::string& num);
};

class calculator {
 public:
  calculator();
  explicit calculator(const std::string& num);
  calculator& operator=(const calculator& calc);
  calculator& operator=(const std::string& num);
  int operator+(const std::string& rhs);
  int operator-(const std::string& rhs);
  int operator/(const std::string& rhs);
  int operator*(const std::string& rhs);

 private:
  std::string lhs_value_;
};

#endif  // MODULES_BORISOV_M_POS_SYSTEMS_CALCULATOR_INCLUDE_BORISOV_M_POS_SYSTEMS_CALCULATOR_H_
