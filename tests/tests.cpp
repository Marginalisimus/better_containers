#include <gtest/gtest.h>
#include <iostream>
#include <dynamic_array/dynamic_array.hpp>
#include <vector/vector.hpp>
#include <string/string.hpp>
#include <linked_list/linked_list.hpp>
#include <doubly_linked_list/linked_list.hpp>


//dynamic_array tests
TEST(Unit, dynamicAddTest) {
	bc::dynamic_array<int> subject{};

    subject.add(1);

	EXPECT_EQ (subject[0], 1);
	EXPECT_EQ (subject.size(), 1);
}


TEST(Unit, dynamicPopTest) {
    bc::dynamic_array<int> subject{};

    subject.add(1);
    subject.pop();

	EXPECT_EQ (subject.size(), 0);
}

TEST(Unit, dynamicRemoveTest) {
    bc::dynamic_array<int> subject{};

    subject.add(1);
    subject.add(2);
    subject.add(3);
    subject.remove(1);

	EXPECT_EQ (subject.size(), 2);
    EXPECT_EQ (subject[0], 1);
    EXPECT_EQ (subject[1], 3);
}

TEST(Unit, dynamicSortTest) {
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

//string tests
TEST(Unit, stringAddTest) {
	bc::string subject{};

    subject.add('H');

	EXPECT_EQ (subject[0], 'H');
	EXPECT_EQ (subject.size(), 1);
}
//-----------------

//vector tests
TEST(Unit, vectorLengthTest) {
	bc::vector subject(3,4);

	EXPECT_EQ (subject.length(), 5);
}
//-----------------

//doulby_linked_list tests
//TEST(Unit, doublyLinkedListAddTest) {
	//bc::d_linked_list<int> subject{};
   // subject.add_last(3);

	//EXPECT_EQ(*subject.begin(), 3);
   // EXPECT_EQ(subject.size(), 1);
//}
//-------------------

//linked_list tests
TEST(Unit, linkedListAddTest) {
	bc::linked_list<int> subject{};
    subject.add(3);

	EXPECT_EQ(*subject.begin(), 3);
    EXPECT_EQ(subject.size(), 1);
}
//--------------------