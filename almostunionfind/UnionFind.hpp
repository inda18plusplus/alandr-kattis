//
// Created by lunar on 05/12/18.
//

#ifndef ALANDR_KATTIS_UNIONFIND_HPP
#define ALANDR_KATTIS_UNIONFIND_HPP

#include <cstddef>
#include <utility>
#include <vector>

class UnionFind {

	int* _id;
	int* _sizes;

	size_t _size;

	bool find(int v1, int v2);
	int findRoot(int val);

public:
	explicit UnionFind(size_t size);

	void unionVals(int v1, int v2);
	void move(int val, int dest);

	void read(int val);

};


#endif //ALANDR_KATTIS_UNIONFIND_HPP
