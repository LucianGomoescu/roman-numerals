#include "Conversion.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  if(argc != 2) {
    cout<<"Command accepts only one argument."<<endl;
    return -1;
  }
  char* inputNumber = argv[1];
  Conversion conversion(inputNumber);
  switch(conversion.GetStatus()) {
    case ConversionStatus::Done:
      cout<<conversion.GetResult()<<endl;
      break;
    case ConversionStatus::InvalidInput:
      cout << "Invalid argument."<<endl;
      break;
  }
  return 0;
}
