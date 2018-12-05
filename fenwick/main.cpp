//
// Created by lunar on 28/11/18.
//

#include <cstdio>
#include <string>

#include "Tree.hpp"

int main() {

	freopen("fenwick.txt", "r", stdin);

	int size, operations;
	scanf("%d %d", &size, &operations);

	Tree t(size);

	for (int i = 0; i < operations; ++i) {
		char c;
		scanf(" %c", &c);

		if(c == '+') {
			int index, value;
			scanf("%d %d", &index, &value);
			t[index] = value;
		} else {
			int index;
			scanf("%d", &index);

			if(index == 0) {
				printf("0\n");
			} else {
				printf("%d\n", t.getUpTo(index - 1));
			}

		}

	}

}