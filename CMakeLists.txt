cmake_minimum_required(VERSION 3.28.3)
project (CMakeTests VERSION 1.0.0 LANGUAGES CXX )

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CTest)
#set( LIB_NAME "thalesSearch" )
#add_subdirectory(src) # This will ask this lib to be build

#target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} .)

set ( TEST_DRIVER "all_tests")
add_subdirectory(tests)    # This will ask the tests to be generated

# -------------------------------
# Running the tests:
# -------------------------------
# cmake -S . -B build
# cmake --build build
# ctest --test-dir build

# More information on: 
# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html
