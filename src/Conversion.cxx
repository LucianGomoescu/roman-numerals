#include "Conversion.h"

#include <cassert>
#include <utility>
#include <vector>

vector<pair<int, string>> gl_romans({
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
});

Conversion::Conversion(string input) :
  m_input(input) {
  DetermineConversionCase();
  switch(m_case) {
    case ConversionCase::RomanToArabic:
      ConvertRomanToArabic();
      break;
    case ConversionCase::ArabicToRoman:
      ConvertArabicToRoman();
      break;
    case ConversionCase::Inconvertible:
      m_status = ConversionStatus::InvalidInput;
      break;
    default:
      assert(false);
  }
}

void Conversion::DetermineConversionCase () {
  if (IsNumber(m_input)) {
    m_case = ConversionCase::ArabicToRoman;
  } else {
    m_case = ConversionCase::RomanToArabic;
  }
}

void Conversion::ConvertArabicToRoman() {
  string roman = "";
  auto num = stoi(m_input);
  while (num > 0) {
      for (auto &[value, symbol]: gl_romans) {
          if (num >= value) {
              num -= value;
              roman += symbol;
              break;
          }
      }
  }
  m_result = roman;
  m_status = ConversionStatus::Done;
}

void Conversion::ConvertRomanToArabic() {
  int arabic = 0;
  int i = 0;
  auto value = gl_romans[i].first;
  auto symbol = gl_romans[i].second;
  auto num = m_input;
  while (!num.empty()) {
    auto x = num.find(symbol);
    if (x == 0) {
      arabic += value;
      num.erase(0, symbol.length());
    } else {
      i++;
      value = gl_romans[i].first;
      symbol = gl_romans[i].second;
    }
  }
  m_result = to_string(arabic);
  m_status = ConversionStatus::Done;
}

bool Conversion::IsNumber(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
