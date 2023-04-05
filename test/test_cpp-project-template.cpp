#include <gtest/gtest.h>
#include <cpp-project-template/cpp-project-template.h>

using namespace cpt;

TEST(TestFoo, foo_doubles_input) {
    EXPECT_EQ(foo(1), 2);
}
