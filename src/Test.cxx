#include "Test.h"

#include "Conversion.h"

TestStatus TestValidRomanToArabic::Run() {
  Conversion conversion("MMXXII");
  conversion.GetStatus();
  return TestStatus::Failed;
}
