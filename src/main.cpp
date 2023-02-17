#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <cpp-project-template/cpp-project-template.h>

int main() {
    BOOST_LOG_TRIVIAL(info) << "C++ Project Template";
    return 0;
}
