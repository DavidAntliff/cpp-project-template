#include <iostream>

#include <cpp-project-template/cpp-project-template.h>
#include <cpp-project-template/logging.h>

using namespace cpt;

int main() {

    BOOST_LOG_TRIVIAL(info) << "C++ Project Template";
    BOOST_LOG_TRIVIAL(debug) << "foo(1) == " << foo(1);

    return 0;
}
