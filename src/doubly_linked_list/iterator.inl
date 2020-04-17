#pragma once
#include "dl_iterator.hpp"

namespace bc {
//-------------------------
template<class T>
inline dl_iterator<T>::dl_iterator(d_node<T>* ptr_) :
	ptr(ptr_) {
}

template<class T>
inline dl_iterator<T>::dl_iterator() :
	ptr(nullptr) {
}

template<class T>
inline T& dl_iterator<T>::operator*() const {
	return ptr->value.value();
}

template<class T>
inline dl_iterator<T>& dl_iterator<T>::operator++() {
	if (ptr->next != nullptr) {
		ptr = ptr->next;
		return *this;
	}
	else {
		std::cerr << "dl_iterator::operator++(): ptr->next was nullptr \n";
		std::abort();
	}
}

template<class T>
inline dl_iterator<T> dl_iterator<T>::operator++(int) {
	dl_iterator copy = *this;
	++(*this);
	return copy;
}

template<class T>
inline dl_iterator<T>& dl_iterator<T>::operator--() {
	if (ptr->prev != nullptr) {
		ptr = ptr->prev;
		return *this;
	}
	else {
		std::cerr << "dl_iterator::operator--(): ptr->prev was nullptr \n";
		std::abort();
	}
}

template<class T>
inline dl_iterator<T> dl_iterator<T>::operator--(int) {
	dl_iterator copy = *this;
	--(*this);
	return copy;
}

template<class T>
inline T* dl_iterator<T>::operator->() const {
	return &(ptr->value.value());
}
template<class T>
bool operator!=(const dl_iterator<T>& lhs, const dl_iterator<T>& rhs) {
	if (lhs.ptr != rhs.ptr) return true;
	return false;
}

template<class T>
inline bool operator==(const dl_iterator<T>& lhs, const dl_iterator<T>& rhs) {
	return !(lhs != rhs);
}
//-------------------------
}//////////////namespace bc