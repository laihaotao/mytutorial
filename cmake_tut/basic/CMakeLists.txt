# define minimum version of cmake
cmake_minimum_required (VERSION 3.8)
# specify project name
project (basic)

# enable c++ 11 features
set (CMAKE_CXX_STANDARD 11)

# add main.cpp file to the variable SOURCE_FILES
set (SOURCE_FILES main.cpp)

# specify executable file name
add_executable (basic ${SOURCE_FILES})

