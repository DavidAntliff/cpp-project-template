# C++ Project Template

A C++ Project structure template, based on the guide by [Mateusz Pusz](https://github.com/mpusz): "CMake + Conan: 3 Years Later":

 * [YouTube Presentation](https://www.youtube.com/watch?v=mrSwJBJ-0z8)
 * [Presentation Slides](https://github.com/train-it-eu/conf-slides/blob/02f6712db703581079b75b8055db2ea4d4685f61/2021.05%20-%20C++Now/CMake%20+%20Conan%20-%203%20years%20later.pdf)
 * Prior art: [mpusz/new-project-template](https://github.com/mpusz/new-project-template)

This is a simplified version of Mateusz's new-project-template, with support for the things I need.

Includes support for:

 * C++20 (can be changed)
 * Core built as library
 * Boost 1.81.0 (via Conan), including Boost::Log
 * GTest 1.12.1 (via Conan)
 * Debug & Release configurations
 * CLion support
 * Pthreads

## Renaming

To convert to your new project name:

 * Search/replace the project name `cpp-project-template`
 * Search/replace the namespace `cpt`
 * Search/replace the header guards `CPT_`

## Building

Before the project can be built, any Conan dependencies must be made available.

Then, `cmake` can be used to generate the build files, and then run the build.

### Conan

#### Create Profiles

If the following profiles do not exist, create them.

Debug:
```
$ conan profile new gcc-11-debug --detect 
$ conan profile update settings.compiler.libcxx=libstdc++11 gcc-11-debug
$ conan profile update settings.compiler.cppstd=20 gcc-11-debug
$ conan profile update settings.build_type=Debug gcc-11-debug
```

Release:
```
$ conan profile new gcc-11-release --detect 
$ conan profile update settings.compiler.libcxx=libstdc++11 gcc-11-release
$ conan profile update settings.compiler.cppstd=20 gcc-11-release
$ conan profile update settings.build_type=Release gcc-11-release
```

#### Install Packages

Debug:

```
$ conan install -if $BUILD_DIR . --build=missing -s build_type=Debug -pr:b=gcc-11-debug
```

Release:

```
$ conan install -if $BUILD_DIR . --build=missing -s build_type=Release -pr:b=gcc-11-release
```

### CMake

Prepare:
```
$ cmake .. \
    -B $BUILD_DIR \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake \
    -DBUILD_TESTS=1 \ 
    -DUSE_STATIC_BOOST=1
```

Build:
```
$ cmake \
    --build $BUILD_DIR \
    --config Release \
    -j 8
```
