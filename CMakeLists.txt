cmake_minimum_required(VERSION 3.25.0)
project(WinCppTemplate VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set output executable file directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("./includes/")

set(MY_EXECUTABLE_NAME "cpp_primer")

add_executable(
  ${MY_EXECUTABLE_NAME}
  "src/chapter16/p913_3.cpp"
)