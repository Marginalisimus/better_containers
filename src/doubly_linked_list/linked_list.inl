#pragma once
#include "d_linked_list.hpp"
#include "dl_iterator.hpp"
#include <cassert>

namespace bc {
//-------------------------
template<class T>
inline void d_linked_list<T>::add_last(T val) {
	add(val, end());
}

template<class T>
inline void d_linked_list<T>::add_first(T val) {
	add(val, begin());
}

template<class T>
inline void d_linked_list<T>::add(T val, iterator it) {
	if (m_size == 0) {
		m_head.next = new d_node<T>(val);
		m_head.next->next = &m_tail;
		m_tail.prev = m_head.next;
	}
	else {
		d_node<T>* temp = new d_node<T>(val);

		d_node<T>* i = it.ptr;
		if(i->prev == nullptr)i->prev = &m_head;
		
		temp->next = i;
		temp->prev = i->prev;
		i->prev->next = temp;
		i->prev = temp;

	}
	++m_size;
}

template<class T>
inline void d_linked_list<T>::remove_last() {
	auto it = end();
	return remove(it);
}

template<class T>
inline void d_linked_list<T>::remove_first() {
	auto it = begin();
	return remove(it);
}

template<class T>
inline void d_linked_list<T>::remove(iterator it) {
	it.ptr->prev->next = it.ptr->next;
	it.ptr->next->prev = it.ptr->prev;
	--m_size;

	delete it.ptr;
}

template<class T>
inline void d_linked_list<T>::clear() {
	for (std::size_t i = 0; i < m_size; ++i) remove_last();
}

template<class T>
inline T& d_linked_list<T>::front() {
	return *(begin());
}

template<class T>
inline T& d_linked_list<T>::back() {
	return *(--end());
}

template<class T>
inline size_t d_linked_list<T>::size() const {
	return m_size;
}

template<class T>
inline bool d_linked_list<T>::empty() const {
	if (m_size == 0)return true;
	return false;
}

template<class T>
inline dl_iterator<T> d_linked_list<T>::begin() {
	return dl_iterator<T>(m_head.next);
}

template<class T>
inline const_dl_iterator<T> d_linked_list<T>::begin() const {
	return const_dl_iterator<T>(m_head.next);
}

template<class T>
inline const_dl_iterator<T> d_linked_list<T>::cbegin() const {
	return const_dl_iterator<T>(m_head.next);
}

template<class T>
inline dl_iterator<T> d_linked_list<T>::end() {
	return dl_iterator<T>(&m_tail);
}

template<class T>
inline const_dl_iterator<T> d_linked_list<T>::end() const {
	return const_dl_iterator<T>(&m_tail);
}

template<class T>
inline const_dl_iterator<T> d_linked_list<T>::cend() const {
	return dl_iterator<T>(&m_tail);
}

template<class T>
inline typename d_linked_list<T>::reverse_iterator d_linked_list<T>::rbegin() {
	return reverse_iterator(end());
}

template<class T>
inline typename d_linked_list<T>::const_reverse_iterator d_linked_list<T>::rbegin() const {
	return const_reverse_iterator(cend());
}

template<class T>
inline typename d_linked_list<T>::const_reverse_iterator d_linked_list<T>::crbegin() const {
	return const_reverse_iterator(cend());
}

template<class T>
inline typename d_linked_list<T>::reverse_iterator d_linked_list<T>::rend() {
	return reverse_iterator(begin());
}

template<class T>
inline typename d_linked_list<T>::const_reverse_iterator d_linked_list<T>::rend() const {
	return const_reverse_iterator(cbegin());
}

template<class T>
inline typename d_linked_list<T>::const_reverse_iterator d_linked_list<T>::crend() const {
	return const_reverse_iterator(cbegin());
}

template<class T>
inline d_linked_list<T>::d_linked_list() :
	m_size(0),
	m_head(),
	m_tail(){
	m_head.next = &m_tail;
	m_tail.prev = &m_head;
}

template<class T>
inline d_linked_list<T>::~d_linked_list() {
	clear();
}
//-------------------------
}//////////////namespace bc