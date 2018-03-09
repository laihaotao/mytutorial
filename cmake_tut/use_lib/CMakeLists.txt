cmake_minimum_required (VERSION 3.8)
project (use_lib)

# new things
include_directories ("${PROJECT_SOURCE_DIR}/Lib")
add_subdirectory (Lib)
# end of new things

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable (use_lib ${SOURCE_FILES})

target_link_libraries (use_lib my_sqrt_lib)
