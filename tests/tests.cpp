#include <gtest/gtest.h>
#include <iostream>
#include <dynamic_array/dynamic_array.hpp>
#include <vector/vector.hpp>
#include <string/string.hpp>
#include <linked_list/linked_list.hpp>


//dynamic_array tests
TEST(Unit, addTest) {
	bc::dynamic_array<int> subject{};

    subject.add(1);

	EXPECT_EQ (subject[0], 1);
	EXPECT_EQ (subject.size(), 1);
}


TEST(Unit, popTest) {
    bc::dynamic_array<int> subject{};

    subject.add(1);
    subject.pop();

	EXPECT_EQ (subject.size(), 0);
}

TEST(Unit, removeTest) {
    bc::dynamic_array<int> subject{};

    subject.add(1);
    subject.add(2);
    subject.add(3);
    subject.remove(1);

	EXPECT_EQ (subject.size(), 2);
    EXPECT_EQ (subject[0], 1);
    EXPECT_EQ (subject[1], 3);
}

TEST(Unit, sort) {
    bc::dynamic_array<int> subject{};

    subject.add(11);
    subject.add(4);
    subject.add(6);
    subject.sort();

	EXPECT_EQ (subject.size(), 3);
    EXPECT_EQ (subject[0], 4);
    EXPECT_EQ (subject[1], 6);
    EXPECT_EQ (subject[2], 11);
}


//-------------------
