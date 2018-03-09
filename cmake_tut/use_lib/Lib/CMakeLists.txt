# scan all source files and put their
# name into the variable DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# add the whole thing as a library
add_library (my_sqrt_lib ${DIR_LIB_SRCS})
