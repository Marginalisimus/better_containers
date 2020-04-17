#pragma once
#include <iostream>
#include "../dynamic_array/dynamic_array.hpp"

namespace bc {
//-------------------------
class string {
	char* str;
	std::size_t allocated_size;
	bool index_valid(std::size_t index, bool allow_null = false) const;//check validity of index
	void check_index(std::size_t index, bool allow_null = false) const;//assert index validity
public:
	std::size_t size() const;//count string length
	std::size_t find(char symbol, std::size_t position = 0) const;//find symbol
	std::size_t find(const dynamic_array<char>& arr, std::size_t position = 0) const;
	std::size_t find_substring(const char* other) const;//find substring
	std::size_t find_substring(const string& other) const;//find substring
	void add(char symbol);//add symbol at last position
	void add(char symbol, std::size_t position);//add symbol at position
	void add_allocated_size(std::size_t increase);//add allocated size
	void remove();//delete last symbol
	void remove(std::size_t position);//delete symbol at position
	void clear();//delete all symbols
	void replace(std::size_t index, std::size_t length,const string& replacement);//replace substring with another string
	void remove_substring(std::size_t index, std::size_t length);//remove substring from given index to index + length
	void add_substring(std::size_t index, const string& substring);//add substring to given index
	const char* data() const;//see str
	string substring(std::size_t index, std::size_t length) const;

	char& operator[](const std::size_t& index);//can change symbols
	const char& operator[](const std::size_t& index) const;//cant change symbols, only view symbol

	string& operator=(const string& other);//assigning str to other
	string& operator=(const char* other);//assigning str to other

	string& operator+=(const string& rhs);//operator +=
	string& operator+=(const char* rhs);//operator +=


	string(std::size_t size = 0);//constructor
	string(const char* another_str);//constructor from string
	string(const string& another);//constructor from another class string
	~string();//destructor
};

std::ostream& operator<<(std::ostream& os, const string& str);//operator output
std::istream& operator>>(std::istream& is, string& str);

//-------------------------
}//////////////namespace bc
#include "string.inl"
