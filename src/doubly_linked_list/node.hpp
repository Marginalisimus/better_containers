#pragma once
#include <optional>

namespace bc {
//-------------------------
template<class T>
struct d_node {
	d_node* next;
	d_node* prev;
	std::optional<T> value;

	d_node(T value_) :
		next(nullptr),
		prev(nullptr),
		value(value_) {
	}

	d_node() :
		next(nullptr),
		prev(nullptr),
		value(){}
};
//-------------------------
}//////////////namespace bc