#pragma once
#include <iostream>

namespace bc {
//-------------------------
template<class T>
struct node {
	T data;
	node* next;

	node(T data_ = 0) :
		data(data_),
		next(nullptr) {
	}
};
//-------------------------
}//////////////namespace bc