# set(BUILD_SHARED_LIBS YES)

#=== SETTING LIBRARY ===#
# add_library(${LIB_NAME} SHARED lib_name.cpp)
add_library(${LIB_NAME} math_lib.cpp)
set_target_properties(${LIB_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER math_lib.hpp)
# Make header available for other targets in the project.
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} .)
target_compile_features( ${LIB_NAME} PRIVATE cxx_std_17 )
target_compile_options( ${LIB_NAME} PRIVATE -Wall -pedantic -O3)
