#include <string>

enum class TestStatus{Passed, Failed};

using namespace std;

class ITest {
public:
  virtual TestStatus Run() = 0;
  virtual string GetName() = 0;
};

class TestValidRomanToArabic: public ITest {
public:
  string GetName() override { return "convert valid roman to arabic"; }
  TestStatus Run() override;
};
