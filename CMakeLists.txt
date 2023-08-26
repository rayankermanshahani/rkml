# set minimum required version of CMake for this project to 3.10
cmake_minimum_required(VERSION 3.10)
# set name of this project
project(runme) 

# set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# list of the source files in the project
set(SOURCE_FILES main.cpp
                 matrix/matrix.cpp
                 ops/ops.cpp
                 engine/engine.cpp)

# creates an executable named mlpproject from the source files
add_executable(runme ${SOURCE_FILES})

# adds the current source directory to the include path
target_include_directories(runme PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# to build:
# 1. go to build subdirectory: `cd /build`
# 2. run:  `cmake ..`
# 3. build the project: `make`
# 5. run the executable: `./runme`

