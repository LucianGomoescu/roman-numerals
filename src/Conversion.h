#include <string>

using namespace std;

enum class ConversionStatus{Done, InvalidInput};

class Conversion {
public:
  Conversion(string input);

  ConversionStatus GetStatus() const { return m_status; }
  string GetResult() const { return m_result; }

private:
  enum class ConversionCase{ RomanToArabic, ArabicToRoman, Inconvertible};

  void DetermineConversionCase();
  void ConvertArabicToRoman();
  void ConvertRomanToArabic();

  bool IsNumber(const string& str);

  string m_input;
  string m_result;
  ConversionCase m_case = ConversionCase::Inconvertible;
  ConversionStatus m_status = ConversionStatus::InvalidInput;
};
