//
// Created by lunar on 04/12/18.
//

#include "Tree.hpp"

#include <cmath>

Tree::Tree(int size) : _size(size) {

	int levels = ceil(log2(size));

	_root = new Node(levels);

}

int& Tree::operator[](int index) {

	return (*_root)[index];

}

int Tree::getUpTo(int index) {

	_root->calcSum();

	Node* node = _root;
	int total = 0;
	for(;;) {

		if((index + 1) == node->_size) {
			total += node->_value;
			break;
		}

		if(node->_lhs->_size <= index) {
			total += node->_lhs->_value;
			index -= node->_lhs->_size;
			node = node->_rhs;
		} else {
			node = node->_lhs;
		}

	}

	return total;

}

int& Tree::Node::operator[](int index) {

	if(_size == 1)
		return _value;

	if(index >= _lhs->_size) {
		return (*_rhs)[index - _rhs->_size];
	} else {
		return (*_lhs)[index];
	}

}

Tree::Node::Node(int levels) {

	_size = pow(2, levels);

	if(levels == 0)
		return;

	_lhs = new Node(levels - 1);
	_rhs = new Node(levels - 1);

}

int Tree::Node::calcSum() {

	if(_lhs != nullptr) {
		_value = _lhs->calcSum() + _rhs->calcSum();
	}

	return _value;

}