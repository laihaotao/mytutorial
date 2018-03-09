# CMake Tutorial

## Basic Example

Assume we have the following directory structure:

\+ - - - - - - - -  
\+ main.cpp  
\+ - - - - - - - -  

Inside the `main.cpp`, I have the following code which is used to calculate the square root of an integer:

```c++
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}

	double in_val = atof(argv[1]);
	double out_val = sqrt(in_val);
	fprintf(stdout, "The square root of %g is %g\n",
	        in_val, out_val);

	return 0;
}
```

I want to compile the main.cpp file to get an executable file. Instead of using the command directory, I would like to use CMake to generate a make file for me.

First of all, I add a new file with name `CMakeLists.txt` in the same directory so now the structure looks like:

\+ - - - - - - - -  
\+ main.cpp  
\+ CMakeLists.txt  
\+ - - - - - - - -  

Inside the new file I add the following code:

```cmake
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
```

Now, we just simply open a terminal, `cd` to the current directory and type the following command, you should be able to see the file being compiled.

```shell
cmake .
make
```

Of course, you need to make sure you already have CMake installed. By checking that you can type:

```shell
 cmake --version
```


## Multi-source File

What happen if I don’t want to use the square root function provided by `<math.h>` instead I want to use my own. So maybe I will write a separate file with that function, now the structure in my directory is following:

\+ - - - - - - - -  
\+ main.cpp  
\+ CMakeLists.txt  
\+  
\+ mysqrt.h  
\+ mysqrt.cpp  
\+ - - - - - - - -  

What I need to do now is that, I need to compile this two cpp file separately and link them together. I have to change my `CMakeLists.txt` file to achieve that:

```

cmake_minimum_required (VERSION 3.8)
project (mul_src)

set(CMAKE_CXX_STANDARD 11)

# new thing
#    search all source file in current 
#    directories and add their name to
#    SOURCE_FILES variable
aux_source_directory (. SOURCE_FILES)
# end of new

add_executable (mul_src ${SOURCE_FILES})
```

Also, need to change a little bit of the `main.cpp` to use my version of `sqrt()` function.

```c++
#include <stdio.h>
#include <stdlib.h>
#include "mysqrt.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}

	double in_val = atof(argv[1]);
	double out_val = mysqrt(in_val);
	fprintf(stdout, "The square root of %g is %g\n",
	        in_val, out_val);

	return 0;
}
```

Repeat the compile procedure by using the command:

```
cmake .
make
```

You should be able to see the executable file appear.

## Multi-level directory

If I want to well structure my code, split different module into different folder. I can do in the following way. Make the directory looks like following (create new file if you don’t have):

\+ - - - - - - - -  
\+ main.cpp  
\+ CMakeLists.txt -> refer as hl_cmakefile  
\+  
\+ Lib  
\+ ++++ mysqrt.h  
\+ ++++ mysqrt.cpp 
\+ ++++ CMakeLists.txt -> refer as sl_cmakefile  
\+ - - - - - - - -  

In the root directory level’s `CMakeLists.txt` file, you need to specify the subdirectory path and ask CMake to link the result from the subfolder.

```
# hl_cmakefile

cmake_minimum_required (VERSION 3.8)
project (use_lib)

# new things
include_directories ("${PROJECT_SOURCE_DIR}/Lib")
add_subdirectory (Lib)
# end of new things

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable (use_lib ${SOURCE_FILES})

# new things
target_link_libraries (use_lib my_sqrt_lib)
# end of new things
```

In the subfolder, you need to specify the code you wan to compile and make it as a library for the high level module to use.

```
# sl_cmakefile

# scan all source files and put their
# name into the variable DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# add the whole thing as a library
add_library (my_sqrt_lib ${DIR_LIB_SRCS})
```
