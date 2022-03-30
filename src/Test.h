#include <string>

enum class TestStatus{Passed, Failed};

using namespace std;

class ITest {
public:
  virtual TestStatus Run() = 0;
  virtual string GetName() = 0;
};

class TestValidRomanToArabic : public ITest {
public:
  string GetName() override { return "convert valid roman to arabic"; }
  TestStatus Run() override;
};

class TestValidArabicToRoman : public ITest {
public:
  string GetName() override { return "convert valid arabic to roman"; }
  TestStatus Run() override;
};

class TestOutOfRangeArabic : public ITest {
public:
  string GetName() override { return "convert out of range arabic numbers"; }
  TestStatus Run() override;
};

class TestNonIntegerNumbers : public ITest {
public:
  string GetName() override { return "convert non-integer numbers"; }
  TestStatus Run() override;
};

class TestNotAllowedSymbols : public ITest {
public:
  string GetName() override { return "convert not allowed symbols"; }
  TestStatus Run() override;
};
