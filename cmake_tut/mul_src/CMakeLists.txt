cmake_minimum_required (VERSION 3.8)
project (mul_src)

set(CMAKE_CXX_STANDARD 11)

# new thing
#   -> search all source file in current 
#      directories and add their name to
#      SOURCE_FILES variable
aux_source_directory (. SOURCE_FILES)
# end of new

add_executable (mul_src ${SOURCE_FILES})
