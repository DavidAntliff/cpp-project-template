#include "cpp-project-template/cpp-project-template.h"

#include <boost/format.hpp>

#include "cpp-project-template/logging.h"

namespace cpt {

int foo(int x) {
    BOOST_LOG_TRIVIAL(debug) << "foo(" << boost::format("%d") % x << ")";
    return 2 * x;
}

} // namespace cpt

