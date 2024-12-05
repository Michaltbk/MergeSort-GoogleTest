#include "pch.h"
#include "MergeSort.h"

TEST(MergeSortTest, AlreadySorted) {
    int array[] = { 1, 2, 3, 4, 5 };
    int expected[] = { 1, 2, 3, 4, 5 };
    int size = 5;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, ReverseOrder) {
    int array[] = { 5, 4, 3, 2, 1 };
    int expected[] = { 1, 2, 3, 4, 5 };
    int size = 5;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, RandomArray) {
    int array[] = { 12, 11, 13, 5, 6, 7 };
    int expected[] = { 5, 6, 7, 11, 12, 13 };
    int size = 6;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, NegativeNumbers) {
    int array[] = { -5, -1, -3, -2, -4 };
    int expected[] = { -5, -4, -3, -2, -1 };
    int size = 5;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, MixedNumbers) {
    int array[] = { -2, 3, -1, 5, 0 };
    int expected[] = { -2, -1, 0, 3, 5 };
    int size = 5;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, EmptyArray) {
    int* array = nullptr;
    int size = 0;

    EXPECT_NO_THROW(MergeSort::sort(array, size));
}

TEST(MergeSortTest, SingleElement) {
    int array[] = { 42 };
    int expected[] = { 42 };
    int size = 1;

    MergeSort::sort(array, size);
    EXPECT_EQ(array[0], expected[0]);
}

TEST(MergeSortTest, Duplicates) {
    int array[] = { 4, 2, 4, 1, 2 };
    int expected[] = { 1, 2, 2, 4, 4 };
    int size = 5;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}
 
TEST(MergeSortTest, MixedWithDuplicates) {
    int array[] = { -2, 3, -1, 5, 0, -2, 3 };
    int expected[] = { -2, -2, -1, 0, 3, 3, 5 };
    int size = 7;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, TwoElementsSorted) {
    int array[] = { 1, 2 };
    int expected[] = { 1, 2 };
    int size = 2;

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, LargeArray) {
    int size = 200;
    int array[200];
    int expected[200];
    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
        expected[i] = i + 1;
    }

    MergeSort::sort(array, size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MergeSortTest, LargeArrayWithMixedNumbers) {
    int size = 200;
    int array[200];
    int expected[200];

    // Wype³nij tablicê losowymi liczbami ujemnymi i dodatnimi.
    for (int i = 0; i < size; ++i) {
        array[i] = (i % 2 == 0) ? -rand() % 1000 : rand() % 1000;
        expected[i] = array[i]; // Skopiuj dane do expected.
    }

    // Posortuj tablicê expected, ¿eby mieæ wynik oczekiwany.
    std::sort(expected, expected + size);

    // Posortuj array przy u¿yciu MergeSort.
    MergeSort::sort(array, size);

    // SprawdŸ, czy array po posortowaniu jest zgodny z expected.
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

