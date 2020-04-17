#pragma once
#include <iostream>
#include "darr_iterator.hpp"

namespace bc {
//-------------------------
template <class T>
class dynamic_array {
public:
	using index_type = size_t;
	using value_type = T;
	using iterator = darr_iterator<T>;
	using const_iterator = darr_const_iterator<T>;

private:
	index_type allocated_size;
	value_type* arr;
	index_type m_size;

public:
	void add(value_type element);
	void pop();
	void remove(index_type index);
	void sort();
	void remove_all(value_type element);
	void change(index_type index, value_type element);
	void change_all(value_type element_to_del, value_type element_to_change);
	void join(const dynamic_array& other);
	bool contains(const dynamic_array& other) const;
	bool check_index(index_type index) const;
	index_type  size()const;
	index_type  count(value_type element) const;
	value_type  accumulate() const;
	index_type  find(value_type element) const;
	//index_type  binary_search(value_type element);

	dynamic_array(index_type size_ = 0);
	dynamic_array(const dynamic_array& other);
	dynamic_array(std::initializer_list<T> ilist);
	~dynamic_array();

	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cend() const;

	dynamic_array& operator=(const dynamic_array& other);

	value_type& operator[](const index_type& index);
	const value_type& operator[](const index_type& index) const;
};
template <class T>
bool operator==(const dynamic_array<T>& reference, const dynamic_array<T>& other);
template <class T>
bool operator!=(const dynamic_array<T>& reference, const dynamic_array<T>& other);
template <class T>
bool operator< (const dynamic_array<T>& reference, const dynamic_array<T>& other);
template <class T>
bool operator<=(const dynamic_array<T>& reference, const dynamic_array<T>& other);
template <class T>
bool operator> (const dynamic_array<T>& reference, const dynamic_array<T>& other);
template <class T>
bool operator>=(const dynamic_array<T>& reference, const dynamic_array<T>& other);

template <class T>
std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& array);
template <class T>
std::istream& operator>>(std::istream& is, dynamic_array<T>& array);
//-------------------------
}//////////////namespace bc
#include "dynamic_array.inl"