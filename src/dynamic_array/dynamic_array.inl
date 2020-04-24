#pragma once
#include "dynamic_array.hpp"
#include "../string/string.hpp"

namespace bc {
//-------------------------
template <class T>
dynamic_array<T>::dynamic_array(index_type size_) :
	allocated_size(size_),
	m_size(size_) {
	arr = new value_type[allocated_size]();
}

template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array& other) :
	allocated_size(other.allocated_size),
	m_size(other.m_size),
	arr(nullptr) {
		arr = new value_type[allocated_size]();
		for (index_type i = 0; i < size(); i++)arr[i] = other.arr[i];
}

template<class T>
inline dynamic_array<T>::dynamic_array(std::initializer_list<T> ilist) :
	allocated_size(ilist.size()),
	m_size(0) {
		arr = new value_type[allocated_size]();
		for (auto it = ilist.begin(); it != ilist.end(); ++it) {
			add(*it);
		}

}

template <class T>
dynamic_array<T>::~dynamic_array() {
	delete[] arr;
}

template<class T>
inline typename dynamic_array<T>::iterator dynamic_array<T>::begin() {
	return iterator(arr);
}

template<class T>
inline typename dynamic_array<T>::const_iterator dynamic_array<T>::begin() const {
	return const_iterator(arr);
}

template<class T>
inline typename dynamic_array<T>::const_iterator dynamic_array<T>::cbegin() const {
	return const_iterator(arr);
}

template<class T>
inline typename dynamic_array<T>::iterator dynamic_array<T>::end() {
	return iterator(arr + size());
}

template<class T>
inline typename dynamic_array<T>::const_iterator dynamic_array<T>::end() const {
	return const_iterator(arr + size());
}

template<class T>
inline typename dynamic_array<T>::const_iterator dynamic_array<T>::cend() const {
	return const_iterator(arr + size());
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array& other) {
	allocated_size = other.allocated_size;
	m_size = other.m_size;

	delete[] arr;
	arr = new value_type[allocated_size]();

	for (index_type i = 0; i < size(); i++)arr[i] = other.arr[i];

	return *this;
}

template <class T>
bool operator==(const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	if (reference.size() == other.size()) {
		for (typename dynamic_array<T>::index_type i = 0; i < reference.size(); i++) {
			if (reference[i] == other[i]);
			else return false;
		}
		return true;
	}
	else return false;
}

template <class T>
bool operator!=(const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	if (!(reference == other))return true;
	return false;
}

template <class T>
bool operator< (const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	for (typename dynamic_array<T>::index_type i = 0; ; i++) {
		if (reference[i] < other[i])return true;
		if (reference[i] > other[i])return false;
		if (i + 1 >= other.size())return false;
		if (i + 1 >= reference.size())return true;
	}
}

template <class T>
bool operator<=(const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	if (reference == other)return true;
	if (reference < other)return true;
	return false;
}

template <class T>
void dynamic_array<T>::add(value_type element) {
	if (size() < allocated_size) {
		m_size++;
		arr[size() - 1] = element;
	}
	else {
		allocated_size += 3;

		value_type* arr2 = new value_type[size()]();
		for (index_type i = 0; i < size(); i++) {
			arr2[i] = arr[i];
		}

		m_size++;

		delete[] arr;
		arr = new value_type[allocated_size]();
		arr[size() - 1] = element;

		for (index_type i = 0; i < size() - 1; i++) {
			arr[i] = arr2[i];
		}

		delete[] arr2;
	}
}

template <class T>
bool operator> (const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	if (reference == other)return false;

	if (!(reference < other))return true;
	return false;
}

template <class T>
bool operator>=(const dynamic_array<T>& reference, const dynamic_array<T>& other) {
	if (!(reference < other))return true;
	return false;
}

template <class T>
typename dynamic_array<T>::value_type& dynamic_array<T>::operator[](const index_type& index) {
	check_index(index);
	return arr[index];
}

template <class T>
const typename dynamic_array<T>::value_type& dynamic_array<T>::operator[](const index_type& index) const {
	check_index(index);
	return arr[index];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& array) {
	os << '{';

	const char* delimiter = "";
	for (typename dynamic_array<T>::const_iterator it = array.begin(); it != array.end(); ++it) {
		os << delimiter << *it;
		delimiter = ", ";
	}
 
	os << '}';
	return os;
}

template <class T>
std::istream& operator>>(std::istream& is, dynamic_array<T>& array) {
	dynamic_array<T> other;
	array = other;

	char temp = 0;

	is >> temp;
	if (temp != '{') {
		is.setstate(std::ios::failbit);
		return is;
	}

	while (is.peek() == ' ' || is.peek() == '\n' || is.peek() == '\t') {
		is.get();
	}

	if (is.peek() == '}') {
		is.get();
		return is;
	}

	T value;

	while (true) {
		is >> value;
		array.add(value);
		if (!is.good()) return is;

		is >> temp;
		if (temp == '}') return is;
		else if (temp != ',') {
			is.setstate(std::ios::failbit);
			return is;
		}
	}

	return is;
}

template <class T>
void dynamic_array<T>::remove(index_type index) {
	if (size() > index && index >= 0) {
		if (allocated_size - size() >= 10) allocated_size = size() + 3;
		value_type* arr2 = new value_type[size()]();

		for (index_type i = 0; i < index; i++)arr2[i] = arr[i];
		for (index_type i = size() - 1; i > index; i--)arr2[i - 1] = arr[i];

		m_size--;
		delete[] arr;
		arr = new value_type[allocated_size]();

		for (index_type i = 0; i < size(); i++) arr[i] = arr2[i];
		delete[] arr2;
	}
}

template <class T>
typename dynamic_array<T>::value_type dynamic_array<T>::accumulate() const {
	value_type rslt = 0;

	for (index_type i = 0; i < size(); i++) {
		rslt += (*this)[i];
	}

	return rslt;
}

template <class T>
typename dynamic_array<T>::index_type dynamic_array<T>::size()const {
	return m_size;
}

template <class T>
bool dynamic_array<T>::contains(const dynamic_array& other) const {
	if (other.size() > size())return false;

	for (index_type i = 0, j = 0; i < size(); i++) {
		j = 0;

		while (other.arr[j] == arr[i] && i < size()) {
			if (j + 1 == other.size())return true;

			j++;
			i++;
		}
	}
	return false;
}
template<class T>
inline bool dynamic_array<T>::check_index(index_type index) const {
	if (size() <= index) {
		std::cerr << "Wrong index. The max index is " << size() - 1 << ". You tried to take an element at the index:" << index << std::endl;
		std::terminate();
		return false;
	}

	if (size() == 0) {
		std::cerr << "array is empty. You can not take an element from an empty array" << std::endl;
		std::terminate();
		return false;
	}

	return true;
}
/*typename dynamic_array<T>::index_type dynamic_array<T>::binary_search(value_type element) {
	sort();

	if (size() % 2 == 0) {
		index_type i = size() / 2;

		for (; i != element;) {
			if (i > element) i /= 2;
			if (i < element) i *= 2;
		}

	}
	else return 2;
}*/

template <class T>
void dynamic_array<T>::join(const dynamic_array& other) {
	for (index_type i = 0; i < other.size(); i++)add(other[i]);
}

template <class T>
typename dynamic_array<T>::index_type dynamic_array<T>::count(value_type element) const {
	index_type rslt = 0;

	for (index_type i = 0; i < size(); i++) {
		if (arr[i] == element)rslt++;
	}

	return rslt;
}

template <class T>
void dynamic_array<T>::remove_all(value_type element) {//O(m_size)
	for (index_type i = 0; i < size(); i++) {
		if ((*this)[i] == element) {
			remove(i);
			i--;
		}
	}
}

template <class T>
void dynamic_array<T>::change(index_type index, value_type element) {
	arr[index] = element;
}

template <class T>
void dynamic_array<T>::change_all(value_type element_to_del, value_type element_to_change) {
	for (index_type i = 0; i < size(); i++) {
		if ((*this)[i] == element_to_del) {
			(*this)[i] = element_to_change;
		}
	}
}

template <class T>
void dynamic_array<T>::pop() {
	if (allocated_size - size() >= 10) {
		allocated_size = size() + 3;
		m_size--;

		value_type* arr2 = new value_type[size()]();

		for (index_type i = 0; i < size() - 1; i++) {
			arr2[i] = arr[i];
		}

		delete[] arr;
		arr = new value_type[allocated_size]();

		for (index_type i = 0; i < size(); i++) {
			arr[i] = arr2[i];
		}

		delete[] arr2;

	}
	else m_size--;
}

template <class T>
void dynamic_array<T>::sort() {

	value_type temp = 0;

	for (index_type i = 0; i < size(); i++) {
		for (index_type j = 0; j < size(); j++) {
			if (arr[i] < arr[j]) {
				temp = arr[j];

				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

template <class T>
typename dynamic_array<T>::index_type dynamic_array<T>::find(value_type element) const {
	for (index_type i = 0; i < size(); i++) {
		if (arr[i] == element) return i;
	}

	return 0;
}
//-------------------------
}//////////////namespace bc