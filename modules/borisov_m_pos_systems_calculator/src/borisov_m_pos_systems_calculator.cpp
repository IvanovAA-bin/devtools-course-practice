// Copyright 2022 Borisov Maxim

#include "include/borisov_m_pos_systems_calculator.h"

#include <cstdlib>
#include <string>

int converter::convert(const std::string& num) {
  if (num.find("0x") != std::string::npos)
    return convert_hex(num);
  else if (is_bin(num))
    return convert_bin(num);
  else if (is_oct(num))
    return convert_oct(num);
  else
    return 0;
}

int converter::convert_hex(const std::string& num) {
  return std::strtol(num.c_str(), nullptr, 16);
}

int converter::convert_bin(const std::string& num) {
  return std::strtol(num.c_str(), nullptr, 2);
}

int converter::convert_oct(const std::string& num) {
  return std::strtol(num.c_str(), nullptr, 8);
}

bool converter::is_hex(const std::string& num) {
  for (auto& x : num) {
    if ((x < '0' || x > '9') && (x < 'A' || x > 'F') && (x < 'a' || x > 'f'))
      return false;
  }
  return true;
}

bool converter::is_bin(const std::string& num) {
  for (auto& x : num) {
    if (x != '1' && x != '0') return false;
  }
  return true;
}

bool converter::is_oct(const std::string& num) {
  for (auto& x : num) {
    if (x < '0' || x > '8') return false;
  }
  return true;
}

calculator::calculator() : lhs_value_("") {}

calculator::calculator(const std::string& num) : lhs_value_(num) {}

calculator& calculator::operator=(const calculator& calc) {
  if (this != &calc) lhs_value_ = calc.lhs_value_;
  return *this;
}

calculator& calculator::operator=(const std::string& num) {
  lhs_value_ = num;
  return *this;
}

int calculator::operator+(const std::string& num) {
  return converter::convert(lhs_value_) + converter::convert(num);
}
int calculator::operator-(const std::string& num) {
  return converter::convert(lhs_value_) - converter::convert(num);
}
int calculator::operator/(const std::string& num) {
  return converter::convert(lhs_value_) / converter::convert(num);
}
int calculator::operator*(const std::string& num) {
  return converter::convert(lhs_value_) * converter::convert(num);
}
