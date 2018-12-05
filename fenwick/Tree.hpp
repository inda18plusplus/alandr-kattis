//
// Created by lunar on 05/12/18.
//

#ifndef ALANDR_KATTIS_TREE_HPP
#define ALANDR_KATTIS_TREE_HPP

#include <vector>

class Tree {

	std::vector<int> _arr;

public:
	Tree(int size);

	void increment(int index, int value);
	int getTo(int index);

};


#endif //ALANDR_KATTIS_TREE_HPP
