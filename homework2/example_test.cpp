#include <gtest/gtest.h>
#include "iostream"
#include "include/string.hpp"

TEST(StringTest, default_constructor) {
    BMSTU::string str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}
TEST(StringTest, size_constructor) {
    BMSTU::string str(5);
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "     ");
}
TEST(StringTest, c_str_constructor) {
    BMSTU::string str("qwe rty");
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), "qwe rty");
}
TEST(StringTest, copy_constructor) {
    BMSTU::string str("qw er ty");
    BMSTU::string copy_str(str);
    ASSERT_EQ(copy_str.size(), 8);
    ASSERT_STREQ(str.c_str(), "qw er ty");
}
TEST(StringTest, assigments_operator) {
    BMSTU::string str("qw er ty");
    BMSTU::string str_2 = str;
    ASSERT_EQ(str_2.size(), 8);
    ASSERT_STREQ(str_2.c_str(), "qw er ty");
}
TEST(StringTest, assigments_c_str_operator) {
    BMSTU::string str = "qw er ty";
    ASSERT_EQ(str.size(), 8);
    ASSERT_STREQ(str.c_str(), "qw er ty");
}
TEST(StringTest, concat) {
    BMSTU::string str("qw");
    BMSTU::string str2("er");
    str = str + str2 + BMSTU::string("ty");
    ASSERT_STREQ(str.c_str(), "qwerty");
}
TEST(StringTest, output_operator) {
    std::ostringstream out;
    BMSTU::string str("qw er");
    BMSTU::string str_2 = " ty";
    out << str << str_2;
    ASSERT_EQ(out.str(), "qw er ty");
}
TEST(StringTest, swap) {
    BMSTU::string str("qwerty");
    BMSTU::string str_2 = "abc";
    swap(str, str_2);
    ASSERT_EQ(str.size(), 3);
    ASSERT_STREQ(str.c_str(), "abc");
    ASSERT_EQ(str_2.size(), 6);
    ASSERT_STREQ(str_2.c_str(), "qwerty");
}
