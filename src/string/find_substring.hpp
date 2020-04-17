#pragma once
#include "string.hpp"

namespace bc {
//-------------------------
inline int find_substring_rk(const string& source, const string& key) {//O(source.size() * key.size() - key.size() * key.size())
	int key_symbol_sum = 0;

	for (int i = 0; i < key.size(); i++) {//O(key.size())
		key_symbol_sum += key[i];
	}

	int source_symbol_sum = 0;

	for (int i = 0; i < key.size(); i++) {//O(key.size())
		source_symbol_sum += source[i];
	}

	for (int i = 0; i < source.size() - key.size() + 1; i++) {//O(source.size() - key.size() + 1)
		if (source_symbol_sum == key_symbol_sum) {
			for (int j = 0; j < key.size() && j + i < source.size() && source[i + j] == key[j]; j++) {//O(key.size())
				if (j == key.size() - 1) return i;
			}
		}

		source_symbol_sum -= source[i];
		source_symbol_sum += source[i + key.size()];

	}

	return source.size();
}

inline int choose_path(const string& source, const string& key, const int& key_pos) {//O(key.size())
	if (key[key.size() - 1] == source[key_pos])return 3;

	for (int i = key.size() - 1; i >= 0; i--) {
		if (key[i] == source[key_pos])return 2;
	}

	return 1;
}

inline void first_path(const string& key, int& key_pos) {//O(1)
	key_pos += key.size();
}

inline void second_path(const string& source, const string& key, int& key_pos) {//O(key.size())
	for (int i = key.size() - 2, j = 1; i >= 0; i--, j++) {
		if (key[i] == source[key_pos]) {
			key_pos += j;
			return;
		}
	}
	key_pos += key.size() - 2;
}

inline int third_path(const string& source, const string& key, int& key_pos) {//O(key.size())
	for (int i = key.size() - 2, j = 1; i >= 0; i--, j++) {
		if (key[i] != source[key_pos - j]) {
			second_path(source, key, key_pos);
			return j;
		}
	}
	return 0;
}

inline int find_substring_bm(const string& source, const string& key) {//O(key.size()*source_size())
	int key_pos = key.size();

	while (third_path(source, key, key_pos) != 0) {//O(source.size())
		int sign = choose_path(source, key, key_pos);

		if (sign == 1) first_path(key, key_pos);
		if (sign == 2) second_path(source, key, key_pos);
		if (sign == 3) third_path(source, key, key_pos);
		if (key_pos >= source.size()) return source.size();
	}

	return key_pos - key.size() + 1;
}
//-------------------------
}//////////////namespace bc