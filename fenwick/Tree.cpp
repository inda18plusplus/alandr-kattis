//
// Created by lunar on 05/12/18.
//

#include "Tree.hpp"

constexpr int LSB(int in) {
	return (in) & (-in);
}

Tree::Tree(int size) : _arr(size + 1, 0) {

}

void Tree::increment(int index, long long value) {

	++index;

	while(index < _arr.size()) {
		_arr[index] += value;
		index += LSB(index);
	}

}
long long Tree::getTo(int firstN) {
	
	if(firstN == 0)
		return 0;

	long long total = 0;
	while(firstN > 0) {
		total += _arr[firstN];
		firstN -= LSB(firstN);
	}

	return total;

}