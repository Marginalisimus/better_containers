#pragma once
#include "const_iterator.hpp"

namespace bc {
//-------------------------

template <class T>
inline const_dl_iterator<T>::const_dl_iterator(d_node<T>* ptr_) :
	ptr(ptr_) {
}

template <class T>
inline const_dl_iterator<T>::const_dl_iterator(const d_node<T>* ptr_) :
	ptr(ptr_) {
}

template <class T>
inline const_dl_iterator<T>::const_dl_iterator() :
	ptr(nullptr) {
}

template<class T>
inline const T& const_dl_iterator<T>::operator*() const {
	return ptr->value.value();
}


template<class T>
inline const_dl_iterator<T>& const_dl_iterator<T>::operator++() {
	if (ptr->next != nullptr) {
		ptr = ptr->next;
		return *this;
	}
	else {
		std::cerr << "const_dl_iterator::operator++(): ptr->next was nullptr \n";
		std::abort();
	}
}

template<class T>
inline const_dl_iterator<T> const_dl_iterator<T>::operator++(int) {
	const_dl_iterator copy = *this;
	++(*this);
	return copy;
}

template<class T>
inline const_dl_iterator<T>& const_dl_iterator<T>::operator--() {
	if (ptr->prev != nullptr) {
		ptr = ptr->prev;
		return *this;
	}
	else {
		std::cerr << "const_dl_iterator::operator--(): ptr->prev was nullptr \n";
		std::abort();
	}
}

template<class T>
inline const_dl_iterator<T> const_dl_iterator<T>::operator--(int) {
	const_dl_iterator copy = *this;
	--(*this);
	return copy;
}

template<class T>
const T* const_dl_iterator<T>::operator->() const {
	return &(ptr->value.value());
}

template<class T>
bool operator!=(const const_dl_iterator<T>& lhs, const const_dl_iterator<T>& rhs) {
	return (lhs.ptr != rhs.ptr);
}

template<class T>
inline bool operator==(const const_dl_iterator<T>& lhs, const const_dl_iterator<T>& rhs) {
	return !(lhs != rhs);
}
//-------------------------
}//////////////namespace bc