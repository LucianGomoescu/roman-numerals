#include "Conversion.h"
#include "Test.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string TestStatusAsString(TestStatus status) {
  switch(status) {
    case TestStatus::Passed:
      return "passed";
    case TestStatus::Failed:
      return "failed";
    default:
      assert(false);
  }
}

int main() {
  int numTests = 0;
  int numFailedTests = 0;
  vector<ITest*> tests;
  tests.push_back(new TestValidRomanToArabic);
  tests.push_back(new TestValidArabicToRoman);
  tests.push_back(new TestOutOfRangeArabic);
  tests.push_back(new TestNonIntegerNumbers);
  tests.push_back(new TestNotAllowedSymbols);
  tests.push_back(new TestLowerCaseRomanNumerals);
  cout<<"TESTS:"<<endl;
  for (auto test : tests) {
      auto status = test->Run();
      cout<<test->GetName()<<": "<<TestStatusAsString(status)<<endl;
      numTests++;
      numFailedTests += (status == TestStatus::Failed) ? 1 : 0;
  }
  cout<<"------------------------"<<endl;
  cout<<numFailedTests<< " out of "<<numTests<<" tests failed."<<endl;
  return 0;
}
