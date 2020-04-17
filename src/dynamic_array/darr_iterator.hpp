#pragma once
#include <iostream>
#include "dynamic_array.hpp"

namespace bc {
//-------------------------
template <class T>
struct darr_iterator {
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::random_access_iterator_tag;

private:
	T* m_ptr;
public:
	darr_iterator(T* ptr = nullptr) :
		m_ptr(ptr) {
	}

	T& operator*() const {
		return *m_ptr;
	}

	darr_iterator& operator++() {
		++m_ptr;
		return *this;
	}

	darr_iterator operator++(int) {
		darr_iterator copy = *this;
		++(*this);
		return copy;
	}

	darr_iterator& operator--() {
		--m_ptr;
		return *this;
	}
	darr_iterator operator--(int) {
		darr_iterator copy = *this;
		--(*this);
		return copy;
	}

	template<class T_>
	friend bool operator==(const darr_iterator<T_>& lhs, const darr_iterator<T_>& rhs);
};

template <class T>
struct darr_const_iterator {
private:
	const T* m_ptr;
public:
	darr_const_iterator(const T* ptr) :
		m_ptr(ptr) {
	}

	const T& operator*() const {
		return *m_ptr;
	}

	darr_const_iterator& operator++() {
		++m_ptr;
		return *this;
	}

	darr_const_iterator operator++(int) {
		darr_const_iterator copy = *this;
		++(*this);
		return copy;
	}

	darr_const_iterator& operator--() {
		--m_ptr;
		return *this;
	}
	darr_const_iterator operator--(int) {
		darr_const_iterator copy = *this;
		--(*this);
		return copy;
	}

	template<class T_>
	friend bool operator==(const darr_const_iterator<T_>& lhs, const darr_const_iterator<T_>& rhs);
};

template<class T>
bool operator==(const darr_iterator<T>& lhs, const darr_iterator<T>& rhs) {
	return lhs.m_ptr == rhs.m_ptr;
}

template<class T>
bool operator!=(const darr_iterator<T>& lhs, const darr_iterator<T>& rhs) {
	return !(lhs == rhs);
}

template<class T>
bool operator==(const darr_const_iterator<T>& lhs, const darr_const_iterator<T>& rhs) {
	return lhs.m_ptr == rhs.m_ptr;
}

template<class T>
bool operator!=(const darr_const_iterator<T>& lhs, const darr_const_iterator<T>& rhs) {
	return !(lhs == rhs);
}
//-------------------------
}//////////////namespace bc