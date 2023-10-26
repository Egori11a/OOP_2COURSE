#include "func.h"
#include <gtest/gtest.h>
#include <utility>



TEST(test_01, basic_test_10)
{
    // Arrange:
    std::string text ="Hello, World!";
    int n = 2;
    char old_value = 'o';
    char new_value = '9';
    // Act:
    function_replace(text, n, old_value, new_value);
    // Assert:
    ASSERT_TRUE(text == std::string("Hello, W9rld!"));
}

TEST(test_01, basic_test_11)
{
    // Arrange:
    std::string text ="futurae generationes";
    int n = 1;
    char old_value = 'u';
    char new_value = 'y';
    // Act:
    function_replace(text, n, old_value, new_value);
    // Assert:
    ASSERT_TRUE(text == std::string("fytyrae generationes"));
}

TEST(test_01, basic_test_12)
{
    // Arrange:
    std::string text ="I like train in the GYM very well!";
    int n = 3;
    char old_value = 'e';
    char new_value = 'G';
    // Act:
    function_replace(text, n, old_value, new_value);
    // Assert:
    ASSERT_TRUE(text == std::string("I like train in the GYM vGry well!"));
}

TEST(test_01, basic_test_13)
{
    // Arrange:
    std::string text ="aaaaaaa";
    int n = 2;
    char old_value = 'a';
    char new_value = '0';
    // Act:
    function_replace(text, n, old_value, new_value);
    // Assert:
    ASSERT_TRUE(text == std::string("a0a0a0a"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}