#pragma once
#include <iostream>
#include <iterator>
#include "d_node.hpp"

namespace bc {
//-------------------------
template<class T>
struct dl_iterator {
private:	
	d_node<T>* ptr;

	dl_iterator(d_node<T>* ptr_);
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using reference = value_type&;
	using pointer = value_type*;
	using iterator_category = std::bidirectionadl_iterator_tag;

	dl_iterator();
	T& operator*() const;

	dl_iterator<T>& operator++();
	dl_iterator<T> operator++(int);
	dl_iterator<T>& operator--();
	dl_iterator<T> operator--(int);

	T* operator->() const;

	template<class T_>
	friend class d_linked_list;

	template<class T_>
	friend bool operator!=(const dl_iterator<T_>& lhs, const dl_iterator<T_>& rhs);

	template<class T_>
	friend bool operator==(const dl_iterator<T_>& lhs, const dl_iterator<T_>& rhs);
};

template<class T_>
bool operator!=(const dl_iterator<T_>& lhs, const dl_iterator<T_>& rhs);

template<class T_>
bool operator==(const dl_iterator<T_>& lhs, const dl_iterator<T_>& rhs);

//-------------------------
}//////////////namespace bc

#include "dl_iterator.inl"