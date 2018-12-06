//
// Created by lunar on 05/12/18.
//

#include <cstdio>
#include <cstddef>
#include <vector>
#include <set>
#include <numeric>

#include "UnionFind.hpp"

int main() {

	freopen("almostunionfind.txt", "r", stdin);

	size_t length;
	int operations;
	while(scanf(" %lu %d", &length, &operations) != EOF) {

		UnionFind u(length);

		for (int i = 0; i < operations; ++i) {
			int command;
			scanf(" %d", &command);

			if(command == 1) {
				int from, to;
				scanf(" %d %d", &from, &to);
				--from;
				--to;

				u.unionVals(from, to);
			} else if(command == 2) {
				int from, to;
				scanf(" %d %d", &from, &to);
				--from;
				--to;

				u.move(from, to);
			} else {
				int set;
				scanf(" %d", &set);
				--set;

				u.read(set);
			}
		}
	}


	return 0;

}