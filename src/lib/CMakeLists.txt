cmake_minimum_required(VERSION 3.24)

find_package(Boost 1.81.0 REQUIRED)

set(SRCS
        dummy.cpp)

set(HDRS
        include/cpp-project-template/cpp-project-template.h)

add_library(cpp-project-template-Lib ${SRCS} ${HDRS})

target_compile_features(cpp-project-template-Lib PUBLIC cxx_std_20)
target_compile_options(cpp-project-template-Lib PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(cpp-project-template-Lib PRIVATE "$<$<CONFIG:Debug>:-O0>")
target_include_directories(cpp-project-template-Lib PUBLIC include)
target_link_libraries(cpp-project-template-Lib PRIVATE Boost::boost)

# Modern CMake recommends use of an ALIAS, for better error handling:
add_library(cpp-project-template::Lib ALIAS cpp-project-template-Lib)
