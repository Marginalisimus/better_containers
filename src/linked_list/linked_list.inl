#pragma once
#include "linked_list.hpp"
#include "iterator.hpp"

namespace bc {
//-------------------------
template<class T>
inline void linked_list<T>::add(T data) {
	if (head == nullptr) {
		head = new node<T>(data);
	}
	else {
		node<T>* temp = new node<T>(data);

		node<T>* iter = head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = temp;
	}
	++m_size;
}

template<class T>
inline void linked_list<T>::add_first(T data) {
	if (head == nullptr) {
		head = new node<T>(data);
	}
	else {
		node<T>* temp = head;
		head = new node<T>(data);
		head->next = temp;
	}
	++m_size;
}

template<class T>
inline void linked_list<T>::pop() {
	if (size() == 0) {
		std::cerr << "Your linked list was empty when you tried to remove last member";
		std::abort();
	}
	if (size() == 1) {
		delete head;
		head = nullptr;
	}
	else {
		node<T>* iter = head;
		node<T>* temp = nullptr;

		for (int i = 0; i < size(); ++i) {
			if (iter->next != nullptr) {
				iter = iter->next;
			}
			if (i + 2 == size()) {
				temp = iter->next;
			}
		}

		delete iter;
		temp = nullptr;
	}
	--m_size;
}

template<class T>
inline void linked_list<T>::remove(size_t index) {
	check_index(index);

	if (index == 0) {
		node<T>* new_head = head;
		head = head->next;
		delete new_head;
		--m_size;
		return;
	}

	node<T>* iter = head;
	node<T>* previous = iter;
	for (int i = 0; i < index; ++i) {
		previous = iter;
		iter = iter->next;
	}
	previous->next = iter->next;
	delete iter;
	--m_size;
}

template<class T>
inline void linked_list<T>::remove(iterator it) {
	int i = 1;
	for (; it.m_ptr->next != nullptr; ++i, ++it);
	remove(size() - i);
}

template<class T>
inline void linked_list<T>::remove_next(iterator it) {
	if (it.m_ptr->next == nullptr) {
		std::cerr << "linked_list::remove_next: You tried to remove element that didn't exist";
	}

	node<T>* temp = it.m_ptr->next->next;
	delete it.m_ptr->next;
	it.m_ptr->next = temp;
	--m_size;
}

template<class T>
inline bool linked_list<T>::check_index(size_t index) const {
	if (index >= size()) {
		std::cerr << "linked_list::check:Wrong index. Max index is " << size() - 1 << ". You tried to take an element at index:" << index << std::endl;
		std::terminate();
		return false;
	}
	if (size() == 0) {
		std::cerr << "linked_list::check_index:linked list is empty. You can not take an element from empty array" << std::endl;
		std::terminate();
		return false;
	}
	return true;
}

template<class T>
inline size_t linked_list<T>::size() const {
	return m_size;
}

template<class T>
inline l_iterator<T> linked_list<T>::begin() {
	return iterator(head);
}

template<class T>
inline const_l_iterator<T> linked_list<T>::begin() const {
	return const_iterator(head);
}

template<class T>
inline const_l_iterator<T> linked_list<T>::cbegin() const {
	return const_iterator(head);
}

template<class T>
inline l_iterator<T> linked_list<T>::end() {
	node<T>* rslt = head;
	for (int i = 1; i < size(); ++i) {
		rslt = rslt->next;
	}
	return iterator(rslt);
}

template<class T>
inline const_l_iterator<T> linked_list<T>::end() const {
	node<T>* rslt = head;
	for (int i = 0; i < size(); ++i) {
		rslt = rslt->next;
	}
	return const_iterator(rslt);
}

template<class T>
inline const_l_iterator<T> linked_list<T>::cend() const {
	node<T>* rslt = head;
	for (int i = 0; i < size(); ++i) {
		rslt = rslt->next;
	}
	return const_iterator(rslt);
}

template<class T>
inline linked_list<T>::linked_list() :
	head(nullptr),
	m_size(0) {
}

template<class T>
inline linked_list<T>::~linked_list() {
	node<T>* iter = head;
	for (size_t i = 0; i < size(); ++i) {
		node<T>* temp = iter->next;
		delete iter;
		iter = temp;
	}
}

template <class T>
std::ostream& operator<<(std::ostream& os, const linked_list<T>& list) {
	os << '{';

	const char* delimiter = "";
	for (typename linked_list<T>::const_iterator it = list.begin(); it != list.end(); ++it) {
		os << delimiter << *it;
		delimiter = ", ";
	}

	os << '}';
	return os;
}
//-------------------------
}//////////////namespace bc