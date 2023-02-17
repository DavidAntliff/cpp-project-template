# Standalone CMake file
# Entry point for customers
# Does not change development environment

cmake_minimum_required(VERSION 3.24)
project(cpp-project-template-Exe)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# If using Conan with boost:shared=False, set -DUSE_STATIC_BOOST when invoking cmake
if(USE_STATIC_BOOST)
    set(Boost_USE_STATIC_LIBS ON)
else()
    set(Boost_USE_STATIC_LIBS OFF)
    add_definitions(-DBOOST_LOG_DYN_LINK)  # Use dynamic linking for boost::log
endif()

find_package(Boost 1.81.0 COMPONENTS filesystem program_options log log_setup REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(lib)

include(GNUInstallDirs)

add_executable(cpp-project-template main.cpp)
target_link_libraries(cpp-project-template PRIVATE Threads::Threads ${Boost_LIBRARIES} cpp-project-template-Lib)
target_compile_features(cpp-project-template INTERFACE cxx_std_20)
target_compile_options(cpp-project-template PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(cpp-project-template PRIVATE "$<$<CONFIG:Debug>:-O0>")
install(TARGETS cpp-project-template EXPORT cpp-project-template-Targets)
