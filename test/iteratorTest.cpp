#include <iterator.h>
#include <vector>
#include <gtest/gtest.h>
//тест на изменение значения
TEST(TestIteratorSuite, TestIterator) {
	// arrange
    std::vector<int> a(10, 10);
    Iterator<int, std::vector<int>> it(&a, 2, 10);

	// act
	(*it) = 5;

	// assert
	ASSERT_EQ(*it, 5);
}
//тест на итерацию по всем элементам
TEST(TestIteratorSuite, TestIteratorTraversal) {
    // arrange
    std::vector<int> a = {1, 2, 3, 4, 5};
    Iterator<int, std::vector<int>> it(&a, 0, a.size());

    // act/assert
    int sum = 0;
    while (it != it.end()) {
        sum += *it;
        ++it;
    }
    ASSERT_EQ(sum, 15);  // 1 + 2 + 3 + 4 + 5 = 15
}

TEST(TestIteratorSuite, TestIteratorComparison) {
    // arrange
    std::vector<int> a = {1, 2, 3, 4, 5};
    Iterator<int, std::vector<int>> it1(&a, 0, a.size());
    Iterator<int, std::vector<int>> it2(&a, 2, a.size());

    // act/assert
    ASSERT_TRUE(it1 != it2);
    it1 = it2;
    ASSERT_TRUE(it1 == it2);
}