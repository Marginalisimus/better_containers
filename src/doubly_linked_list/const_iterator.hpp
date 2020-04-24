#pragma once
#include <iostream>
#include <iterator>
#include <cstddef>
#include "node.hpp"

namespace bc {
//-------------------------
template<class T>
struct const_dl_iterator {
private:
	const d_node<T>* ptr;

	const_dl_iterator(d_node<T>* ptr_);
	const_dl_iterator(const d_node<T>* ptr_);
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using reference = value_type&;
	using pointer = value_type*;
	using iterator_category = std::bidirectional_iterator_tag;

	const_dl_iterator();
	const T& operator*() const;

	const_dl_iterator<T>& operator++();
	const_dl_iterator<T> operator++(int);
	const_dl_iterator<T>& operator--();
	const_dl_iterator<T> operator--(int);

	const T* operator->() const;

	template<class T_>	
	friend class d_linked_list;

	template<class T_>
	friend bool operator!=(const const_dl_iterator<T_>& lhs, const const_dl_iterator<T_>& rhs);

	template<class T_>
	friend bool operator==(const const_dl_iterator<T_>& lhs, const const_dl_iterator<T_>& rhs);
};

template<class T>
bool operator!=(const const_dl_iterator<T>& lhs, const const_dl_iterator<T>& rhs);

template<class T>
bool operator==(const const_dl_iterator<T>& lhs, const const_dl_iterator<T>& rhs);
//-------------------------
}//////////////namespace bc

#include "const_iterator.inl"