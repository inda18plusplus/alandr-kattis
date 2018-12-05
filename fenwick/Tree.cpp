//
// Created by lunar on 05/12/18.
//

#include "Tree.hpp"

constexpr int LSB(int in) {
	return (in) & (-in);
}

Tree::Tree(int size) : _arr(size + 1, 0) {

}

void Tree::increment(int index, int value) {

	while(index < _arr.size()) {
		_arr[index] += value;
		index += LSB(index);
	}

}
int Tree::getTo(int index) {

	int total = 0;
	while(index > 0) {
		total += _arr[index];
		index -= LSB(index);
	}

	return total;

}