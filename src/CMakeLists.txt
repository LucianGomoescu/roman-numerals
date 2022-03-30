project(RomanNumerals)
CMAKE_MINIMUM_REQUIRED ( VERSION 3.0)

add_executable (convertRoman
  main.cxx
  Conversion.cxx
)

add_executable(test
  Conversion.cxx
  Test.cxx
  TestMain.cxx
)
