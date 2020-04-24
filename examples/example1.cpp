#include <iostream>
#include <dynamic_array/dynamic_array.hpp>
#include <vector/vector.hpp>
#include <string/string.hpp>
#include <linked_list/linked_list.hpp>
#include <doubly_linked_list/linked_list.hpp>


int main() {
	bc::d_linked_list<int> subject{};
    	subject.add_last(3);


    	std::cout << *subject.begin() << std::endl << subject.size() << std::endl;
}