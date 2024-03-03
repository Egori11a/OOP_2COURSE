#include <allocator.h>
#include <gtest/gtest.h>
TEST(TestAllocatorSuite, TestAllocator) {
	// arrange
    Allocator<int, 100> allocator;

	// Ну мы просто знаем, что функция должна вернуть bad_alloc

	// assert
	ASSERT_THROW(allocator.allocate(101), std::bad_alloc);
}
//Тестирование выделения памяти для 0 элементов
TEST(TestAllocatorSuite, AllocateZeroElements) {
    Allocator<int, 100> allocator;
    ASSERT_NO_THROW({int* ptr = allocator.allocate(0);
        // Проверки успешного выделения 0 элементов
        });
}

TEST(TestAllocatorSuite, AllocateMaxValueForAnotherType) {
    Allocator<double, 100> allocator;
    ASSERT_THROW(allocator.allocate(std::numeric_limits<int>::max()), std::bad_alloc);
}
//Тестирование выделения памяти для нуля элементов с непустым аллокатором
TEST(TestAllocatorSuite, AllocateZeroElementsWithNonEmptyAllocator) {
    Allocator<int, 100> allocator;
    int* ptr = allocator.allocate(50);
    ASSERT_NO_THROW({
        int* zeroPtr = allocator.allocate(0);
        // Проверки успешного выделения 0 элементов, если необходимо
    });
    allocator.deallocate(ptr, 50);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}