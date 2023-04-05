cmake_minimum_required(VERSION 3.24)
project(cpp-project-template-Tests)

find_package(GTest 1.12.1 REQUIRED)

if (NOT TARGET cpp-project-template::Lib)
    find_package(cpp-project-template::Lib CONFIG REQUIRED)
endif()

find_package(Boost 1.81.0 COMPONENTS filesystem REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(cpp-project-template-Tests test_cpp-project-template.cpp)
target_link_libraries(cpp-project-template-Tests
        PRIVATE
            Threads::Threads
            cpp-project-template::Lib
            GTest::gtest_main
            ${Boost_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(cpp-project-template-Tests)
