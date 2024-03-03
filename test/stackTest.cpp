#include <allocator.h>
#include <stack.h>
#include <gtest/gtest.h>

TEST(TestStackSuite, TestStack) {
	// arrange
    Stack< int, Allocator<int, 10> > s;

	// act
	s.push(1);
	s.push(2);
	s.push(3);
	s.print();

	// assert
	ASSERT_EQ(s.pop(), 3);
	ASSERT_EQ(s.pop(), 2);
	ASSERT_EQ(s.pop(), 1);
	s.print();
}

TEST(TestStackSuite, TestEmptyStack) {
    // arrange
    Stack<int, Allocator<int, 10> > s;

    // act/assert
    ASSERT_THROW(s.pop(), std::out_of_range);
}
