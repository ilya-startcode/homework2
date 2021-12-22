#include <gtest/gtest.h>
#include "iostream"
#include "include/string.hpp"

TEST(StringTest, Concat) {
    BMSTU::string str("String");
    BMSTU::string str2("Pig");
    str = str + str2 + BMSTU::string("LOOOOL");

    std::cout << str;
    ASSERT_STREQ(str.c_str(), "StringPigLOOOOL");
}
