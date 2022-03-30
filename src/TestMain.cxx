#include "Conversion.h"
#include "Test.h"

#include <cassert>
#include <iostream>
#include <string>

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
  cout<<"TESTS:"<<endl;
  {
    TestValidRomanToArabic test;
    auto status = test.Run();
    cout<<test.GetName()<<": "<<TestStatusAsString(status)<<endl;
    numTests++;
    numFailedTests += (status == TestStatus::Failed) ? 1 : 0;
  }
  {
    TestValidArabicToRoman test;
    auto status = test.Run();
    cout<<test.GetName()<<": "<<TestStatusAsString(status)<<endl;
    numTests++;
    numFailedTests += (status == TestStatus::Failed) ? 1 : 0;
  }
  cout<<"------------------------"<<endl;
  cout<<numFailedTests<< " out of "<<numTests<<" tests failed."<<endl;
  return 0;
}
