//
// Created by lunar on 06/12/18.
//

#ifndef ALANDR_KATTIS_TREE_HPP
#define ALANDR_KATTIS_TREE_HPP

#include <functional>
#include <stdexcept>
#include <vector>

#include <cmath>

template<typename T>
T ceilPow2(T in) {
	auto exponent = (T)ceil(log2(in));

	return (T)pow(2, exponent);
}

template<typename T, T _empty, class Aggr = std::plus<T>>
class Tree {
public:
	typedef typename std::vector<T>::size_type index_type;

private:
	Aggr aggr;

	index_type _size;
	std::vector<T> _arr;

	constexpr index_type bottom_start() {
		return ceilPow2<>(_size);
	}

public:
	Tree(index_type size) : _size(size), _arr(ceilPow2<>(_size) << 1, _empty) {

		for (index_type i = 0; i < _size; ++i) {
			set(i, _empty);
		}

	}
	void resize(index_type newSize) { //Will delete the entire tree

		_arr.resize(ceilPow2<>(newSize) << 1, empty());
		_size = newSize;

		for (index_type i = 0; i < _size; ++i) {
			set(i, _empty);
		}

	}

	void set(index_type index, T val) {

		if(index >= _size)
			throw std::out_of_range("Invalid index");

		index += bottom_start();
		_arr[index] = val;

		for(index_type i = (index >> 1); i; i >>= 1) {

			_arr[i] = aggr(_arr[i << 1], _arr[(i << 1) + 1]);

		}

	}
	T get(index_type index) {
		return _arr[bottom_start() + index];
	}
	T valueTo(index_type index) {

		T result = get(index);

		bool rhs = index % 2;

		for(index_type i = (index + bottom_start()) >> 1; i; i >>= 1) {
			if(rhs)
				result = aggr(result, _arr[i << 1]);

			rhs = i % 2;
		}

		return result;

	}

	constexpr index_type size() { return _size; }
	constexpr T empty() { return _empty; }


	index_type first() {

		index_type index = 1;

		while(index < bottom_start()) {

			index_type c1 = index << 1;
			index_type c2 = c1 + 1;

			index <<= 1;

			if(_arr[c1] == empty()) {
				++index;
			}

		}

		if(index == _arr.size() - 1 && _arr[index] == empty()) {
			return _size;
		}

		return index - bottom_start();
	}
	template<class Comp>
	index_type findLowest() {

		Comp c;

		index_type index = 1;

		while(index < bottom_start()) {

			index_type c1 = index << 1;
			index_type c2 = c1 + 1;

			index <<= 1;

			if(!c(_arr[c1], _arr[c2])) {
				++index;
			}

		}

		return index - bottom_start();

	}

};



#endif //ALANDR_KATTIS_TREE_HPP
