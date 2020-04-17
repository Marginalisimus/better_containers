#pragma once
#include "string/string.hpp"
#include <cstring>
#include <cstdlib>
#include <iostream>

namespace bc {
//-------------------------
inline bool string::index_valid(std::size_t index, bool allow_null) const {
	if (allow_null == true && index > size())return false;
	if (allow_null == false && index >= size())return false;

	return true;
}

inline void string::check_index(std::size_t index, bool allow_null) const {
	if (!index_valid(index, allow_null)) {
		std::cout << "You tried to take an element with wrond index:" << index << std::endl << "string was:" << *this << std::endl;
		std::abort();
	}
}

inline std::size_t string::size() const {
	return std::strlen(str);
}

inline std::size_t string::find(char symbol, std::size_t position) const {
	check_index(position);

	std::size_t i = position;

	for (; str[i] != symbol; i++) {
		if (i - 1 >= size())return size();
	}
	return i;
}

inline std::size_t string::find(const dynamic_array<char>& arr, std::size_t position)  const{
	std::size_t result = size();

	for (std::size_t i = 0; i < arr.size(); ++i) {
		std::size_t index = find(arr[i], position);

		if (index < result) result = index;
	}

	return result;
}

inline std::size_t string::find_substring(const char* other) const {//O(size()*other.size())
	for (std::size_t i = 0; i < size(); i++) {
		for (std::size_t j = 0; other[j] == str[i + j] && j + i < size() && j < std::strlen(other); j++) {
			if (j == std::strlen(other) - 1) return i;
		}
	}

	return size();
}

inline std::size_t string::find_substring(const string& other) const {
	return find_substring(other.str);
}

inline void string::add(char symbol) {
	if (allocated_size > size() + 1) {
		str[size() + 1] = 0;
		str[size()] = symbol;
	}
	else {
		add_allocated_size(5);
		str[size() + 1] = 0;
		str[size()] = symbol;
	}
}

inline void string::add(char symbol, std::size_t position) {
	check_index(position);

	char* temp = new char[size() + 2]();
	for (std::size_t i = 0; i < position; i++) {
		temp[i] = str[i];
	}

	temp[position] = symbol;

	for (std::size_t i = position; i < size(); i++) {
		temp[i + 1] = str[i];
	}

	add_allocated_size(3);

	for (std::size_t i = 0; i < std::strlen(temp); i++) {
		str[i] = temp[i];
	}

	delete[] temp;
}

inline void string::add_allocated_size(std::size_t increase) {
	char* temp = str;

	str = new char[allocated_size + increase]();

	for (std::size_t i = 0; i < allocated_size; i++)str[i] = temp[i];

	allocated_size += increase;

	delete[] temp;
}

inline void string::remove() {
	str[size() - 1] = 0;
}

inline void string::remove(std::size_t position) {
	check_index(position, true);
		
	for (std::size_t i = position; i < size(); i++) {
		str[i] = str[i + 1];
	}
}

inline void string::clear() {
	str[0] = 0;
}

inline void string::replace(std::size_t index, std::size_t length, const string& replacement) {
	remove_substring(index, length);
	add_substring(index, replacement);
}

inline void string::remove_substring(std::size_t index, std::size_t length) {
	if (index_valid(index + length) && index_valid(index)) {
		for (std::size_t i = 0; i < length; i++) {
			remove(index);
		}
	}

	else std::abort();
}

inline void string::add_substring(std::size_t index, const string& substring) {
	for (std::size_t i = 0; i < substring.size(); i++) {
		add(substring[i], index + i);
	}
}

inline const char* string::data() const{
	return str;
}

inline string string::substring(std::size_t index, std::size_t length) const {
	check_index(index);
	check_index(index + length, true);

	string rslt;
	for (std::size_t i = index; i <= index + length; i++) {
		rslt.add((*this)[i]);
	}

	return rslt;
}

inline char& string::operator[](const std::size_t& index) {
	check_index(index);

	return str[index];
}
inline const char& string::operator[](const std::size_t& index) const {
	check_index(index);

	return str[index];
}

inline string& string::operator=(const string& other) {
	*this = other.str;

	return *this;
}
inline string& string::operator=(const char* other) {
	delete[] str;
	allocated_size = std::strlen(other) + 1;
	str = new char[allocated_size]();

	for (std::size_t i = 0; i <= size(); i++)str[i] = other[i];

	return *this;
}

inline string& string::operator+=(const string& rhs) {
	for (std::size_t i = 0; i < rhs.size(); i++) {
		add(rhs[i]);
	}

	return *this;
}

inline string& string::operator+=(const char* rhs) {
	for (std::size_t i = 0; i < std::strlen(rhs); i++) {
		add(rhs[i]);
	}

	return *this;
}

inline string::string(const std::size_t size) {
	allocated_size = size + 1;
	str = new char[allocated_size]();
}

inline string::string(const char* another_str) {
	str = new char[std::strlen(another_str) + 1]();
	std::strcpy(str, another_str);

	allocated_size = size() + 1;
}

inline string::string(const string& another) :
	string(another.str) {
}

inline string::~string() {
	delete[] str;
}

inline std::ostream& operator<<(std::ostream & os, const string & str) {
	os << '"';

	for (std::size_t i = 0; i < str.size(); i++) {
		os << str[i];
	}

	os << '"';

	return os;
}

inline std::istream& operator>>(std::istream& is, string& str) {
	str.clear();

	char symbol = 0;

	is >> symbol;

	if (symbol != '"') {
		is.setstate(std::ios::failbit);
		return is;
	}

	symbol = is.get();

	while (symbol != '"') {
		if (symbol == '\\') {
			symbol = is.get();
			switch (symbol) {
			case 'a':
				str.add('\a');
				break;
			case 'b':
				str.add('\b');
				break;
			case 't':
				str.add('\t');
				break;
			case 'n':
				str.add('\n');
				break;
			case '"':
				str.add('"');
				break;
			case '\'':
				str.add('\'');
				break;
			case '\\':
				str.add('\\');
				break;
			default:
				is.setstate(std::ios::failbit);
				return is;
			}
		}
		else {
			str.add(symbol);
		}

		symbol = is.get();
	}

	return is;
}
//-------------------------
}//////////////namespace bc