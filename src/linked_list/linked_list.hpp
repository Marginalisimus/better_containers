#pragma once
#include <iostream>
#include "node.hpp"
#include "iterator.hpp"

namespace bc {
//-------------------------
template<class T>
class linked_list {
private:
	node<T>* head;//beginning
	std::size_t m_size;

public:
	using iterator = l_iterator<T>;
	using const_iterator = const_l_iterator<T>;

	//addition---------------------
	void add(T data);
	void add_first(T data);
	//-----------------------------

	//erasing----------------------
	void pop();
	void remove(size_t index);
	void remove(iterator it);
	void remove_next(iterator it);
	//-----------------------------

	//utility----------------------
	bool check_index(size_t index) const;
	size_t size() const;
	//-----------------------------

	//iterators--------------------
	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cend() const;
	//-----------------------------

	//constructors/destructors-----
	linked_list();
	~linked_list();
	//-----------------------------

	//operator---------------------
	template<class T_>
	friend std::ostream& operator<<(std::ostream& os, const linked_list<T_>& list);
	//-----------------------------
};
//-------------------------
}//////////////namespace bc
#include "linked_list.inl"