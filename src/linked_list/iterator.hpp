#pragma once
#include <iostream>
#include "node.hpp"

namespace bc {
//-------------------------
template<class T>
struct l_iterator {
private:
	node<T>* m_ptr;

public:
	l_iterator(node<T>* ptr) :
		m_ptr(ptr){
	}

	T& operator*() const {
		return m_ptr->data;
	}

	l_iterator& operator++() {
		m_ptr = m_ptr->next;
		return *this;
	}

	l_iterator operator++(int) {
		l_iterator copy = *this;
		++(*this);
		return copy;
	}

	template<class T_>
	friend bool operator==(const l_iterator<T_>& lhs, const l_iterator<T_>& rhs);

	template<class T_>
	friend class linked_list;
};

template<class T>
struct const_l_iterator {
private:
	const node<T>* m_ptr;
public:
	const_l_iterator(node<T>* ptr) :
		m_ptr(ptr) {
	}

	const T& operator*() const {
		return m_ptr->data;
	}

	const_l_iterator& operator++() {
		m_ptr = m_ptr->next;
		return *this;
	}

	const_l_iterator operator++(int) {
		const_l_iterator copy = *this;
		++(*this);
		return copy;
	}

	template<class T_>
	friend bool operator==(const const_l_iterator<T_>& lhs, const const_l_iterator<T_>& rhs);

	template<class T_>
	friend class linked_list;
};

template<class T>
bool operator==(const l_iterator<T>& lhs, const l_iterator<T>& rhs) {
	return lhs.m_ptr == rhs.m_ptr;
}

template<class T>
bool operator!=(const l_iterator<T>& lhs, const l_iterator<T>& rhs) {
	return !(lhs == rhs);
}

template<class T>
bool operator==(const const_l_iterator<T>& lhs, const const_l_iterator<T>& rhs) {
	return lhs.m_ptr == rhs.m_ptr;
}

template<class T>
bool operator!=(const const_l_iterator<T>& lhs, const const_l_iterator<T>& rhs) {
	return !(lhs == rhs);
}
//-------------------------
}//////////////namespace bc