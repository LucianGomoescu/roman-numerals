#include <string>

using namespace std;

enum class ConversionStatus{Done, InvalidInput};

class Conversion {
public:
  Conversion(string input) : m_input(input) {}

  ConversionStatus GetStatus() const { return m_status; }
  string GetResult() const { return m_result; }

private:
  string m_input;
  string m_result;
  ConversionStatus m_status = ConversionStatus::InvalidInput;
};
