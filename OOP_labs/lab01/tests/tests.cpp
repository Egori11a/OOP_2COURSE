#include "../include/task.hpp"
#include <gtest/gtest.h>
#include <utility>
#include <string>

TEST(test_function_replace, basic_test_1) {
    // Arrange:
    std::string text = "Hello, World!";
    int n = 2;
    char old_value = 'o';
    char new_value = '9';

    // Act:
    std::string result = function_replace(text, n, old_value, new_value);

    // Assert:
    ASSERT_TRUE(result == std::string("Hello, W9rld!"));
}

TEST(test_function_replace, basic_test_2) {
    // Arrange:
    std::string text = "Testing function_replace function";
    int n = 3;
    char old_value = 't';
    char new_value = '#';

    // Act:
    std::string result = function_replace(text, n, old_value, new_value);

    // Assert:
    ASSERT_TRUE(result == std::string("Testing function_replace func#ion"));
}

TEST(test_function_replace, no_change_test) {
    // Arrange:
    std::string text = "No changes expected";
    int n = 0; 
    char old_value = 'a';
    char new_value = '9';

    // Act:
    std::string result = function_replace(text, n, old_value, new_value);

    // Assert:
    ASSERT_TRUE(result == std::string("No changes expected"));
}

TEST(test_function_replace, invalid_n_test) {
    // Arrange:
    std::string text = "Invalid n test";
    int n = 10;
    char old_value = 'e';
    char new_value = '*';

    // Act:
    std::string result = function_replace(text, n, old_value, new_value);

    // Assert:
    ASSERT_TRUE(result == std::string("Invalid n test"));
}

TEST(test_function_replace, invalid_old_value) {
    // Arrange:
    std::string text = "Invalid old_value test";
    int n = 2;
    char old_value = '*';
    char new_value = '!';

    // Act:
    std::string result = function_replace(text, n, old_value, new_value);

    // Assert:
    ASSERT_TRUE(result == std::string("Invalid old_value test"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}