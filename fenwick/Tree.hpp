//
// Created by lunar on 05/12/18.
//

#ifndef ALANDR_KATTIS_TREE_HPP
#define ALANDR_KATTIS_TREE_HPP

#include <vector>

class Tree {

	std::vector<long long> _arr;

public:
	Tree(int size);

	void increment(int index, long long value);
	long long getTo(int firstN);

};


#endif //ALANDR_KATTIS_TREE_HPP
