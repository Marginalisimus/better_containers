#include <iostream>
#include <dynamic_array/dynamic_array.hpp>
#include <vector/vector.hpp>
#include <string/string.hpp>
#include <linked_list/linked_list.hpp>


int main() {
	bc::dynamic_array<int> subject{};

	for(int i = 0; i < 6; ++i){
		subject.add(i);
	}
	
    std::cout << subject << std::endl;
}