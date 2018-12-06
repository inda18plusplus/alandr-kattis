//
// Created by lunar on 05/12/18.
//

#include "UnionFind.hpp"

#include <cstdlib>
#include <cstring>
#include <cstdio>

UnionFind::UnionFind(size_t size) : _size(size) {

	int* mem = new int[_size*2]; //I have no idea whether this is quicker, but maybe? Might prevent some cache-misses

	_id = mem;
	_sizes = mem + _size;

	for (int i = 0; i < _size; ++i) {
		_id[i] = i;
		_sizes[i] = 1;
	}

}

bool UnionFind::find(int v1, int v2) {
	return findRoot(v1) == findRoot(v2);
}
int UnionFind::findRoot(int val) {

	while(val != _id[val]) {
		val = _id[val];
	}

	return val;
}

void UnionFind::unionVals(int v1, int v2) {

	int from = findRoot(v1);
	int to = findRoot(v2);

	if(_sizes[from] > _sizes[to]) {
		std::swap(from, to);
	}

	_id[from] = to;
	_sizes[to] += _sizes[from];

}
void UnionFind::move(int val, int dest) {

	dest = findRoot(dest);

	int newRoot = findRoot(val);
	if(newRoot == val) { //val is the root of its tree, relink to first child instead (or itself if the set is empty)
		for (int i = 0; i < _size; ++i) {
			if(_id[i] == val && i != val) {
				newRoot = i;
				break;
			}
		}
	}

	for (int i = 0; i < _size; ++i) {
		if(_id[i] == val) {
			_id[i] = newRoot;
		}
	}

	_sizes[newRoot] = _sizes[val] - 1;
	_sizes[val] = 1;

	_id[val] = dest;

	_sizes[dest] += 1;

}

void UnionFind::read(int val) {

	int root = findRoot(val);

	size_t sz = 0;
	int sum = 0;

	for (int i = 0; i < _size; ++i) {
		if(find(root, i)) {
			++sz;
			sum += i;

			_id[i] = root;
			_sizes[i] = 1;
		}
	}

	printf("%lu %d\n", sz, sum + sz);

}