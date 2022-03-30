#include "Test.h"

#include "Conversion.h"

#include <vector>

// These are some arabic numbers and their correct representation with Roman
// numerals.
vector<string> gl_arabicNums {"1", "2", "3", "4", "5",
                           "6", "7", "8", "9", "10",
                           "11", "13", "14", "46", "87",
                           "101", "345", "1453", "1989", "4000"};

vector<string> gl_romanNums {"I", "II", "III", "IV", "V",
                          "VI", "VII", "VIII", "IX", "X",
                          "XI", "XIII", "XIV", "XLVI", "LXXXVII",
                          "CI", "CCCXLV", "MCDLIII", "MCMLXXXIX", "MMMM"};

TestStatus TestValidRomanToArabic::Run() {
  Conversion conversion("MMXXII");
  conversion.GetStatus();
  return TestStatus::Failed;
}

TestStatus TestValidArabicToRoman::Run() {
  int i = 0;
  for (auto arabicNum : gl_arabicNums) {
    Conversion conversion(arabicNum);
    auto result = conversion.GetResult();
    auto cStatus = conversion.GetStatus();
    TestStatus tStatus = (cStatus == ConversionStatus::Done &&
                          result == gl_romanNums[i]) ?
                          TestStatus::Passed : TestStatus::Failed;
    if (tStatus == TestStatus::Failed) { return TestStatus::Failed; }
    i++;
  }
  return TestStatus::Passed;
}
