# Project structure based on:
#  https://www.youtube.com/watch?v=mrSwJBJ-0z8
#  https://github.com/train-it-eu/conf-slides/blob/02f6712db703581079b75b8055db2ea4d4685f61/2021.05%20-%20C++Now/CMake%20+%20Conan%20-%203%20years%20later.pdf
#
# Old presentation:
#  https://www.youtube.com/watch?v=S4QSKLXdTtA
#  https://github.com/CppCon/CppCon2018/blob/master/Presentations/git_cmake_conan_how_to_ship_and_reuse_our_cpp_projects/git_cmake_conan_how_to_ship_and_reuse_our_cpp_projects__mateusz_pusz__cppcon_2018.pdf
#
# To build natively, use `conan_paths.cmake` as the toolchain:
#
#    cmake -DCMAKE_TOOLCHAIN_FILE=build/conan_paths.cmake
#
# https://docs.conan.io/en/1.5/integrations/cmake/cmake_paths_generator.html#included-as-a-toolchain


# Entry point for all development (IDE)
cmake_minimum_required(VERSION 3.24)

# Modify and search/replace across all CMakeLists.txt files:
project(cpp-project-template-Dev)

option(BUILD_TESTS "Build test binaries" OFF)

add_subdirectory(src)

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif(BUILD_TESTS)
