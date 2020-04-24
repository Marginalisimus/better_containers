#pragma once
#include <iostream>
#include <cstddef>
#include <iterator>
#include "node.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"

namespace bc {
//-------------------------
template<class T>
class d_linked_list {
private:
	std::size_t m_size;
	d_node<T> m_head;
	d_node<T> m_tail;
public:
	using value_type = T;//what following the iterator returns
	using size_type = size_t;
	using difference_type = std::ptrdiff_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using iterator = dl_iterator<T>;
	using const_iterator = const_dl_iterator<T>;
	using reverse_iterator = std::reverse_iterator<dl_iterator<T>>;
	using const_reverse_iterator = std::reverse_iterator<const_dl_iterator<T>>;

	void add_last(T val);
	void add_first(T val);
	void add(T val, iterator it);

	void remove_last();
	void remove_first();
	void remove(iterator it);
	void clear();

	T& front();
	T& back();

	std::size_t size() const;
	bool empty() const;
	
	dl_iterator<T> begin();
	const_dl_iterator<T> begin() const;
	const_dl_iterator<T> cbegin() const;

	dl_iterator<T> end();
	const_dl_iterator<T> end() const;
	const_dl_iterator<T> cend() const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator crbegin() const;

	reverse_iterator rend();
	const_reverse_iterator rend() const;
	const_reverse_iterator crend() const;

	

	d_linked_list();
	~d_linked_list();
};

template <class T>
std::ostream& operator<<(std::ostream& os, const d_linked_list<T>& list){
	for(auto el : list){
		os << el << " ";
	}
	os << std::endl;

	return os;
}
//-------------------------
}//////////////namespace bc
#include "linked_list.inl"
