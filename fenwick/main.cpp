//
// Created by lunar on 28/11/18.
//

#include <cstdio>
#include <string>

#include "Tree.hpp"

int main() {

	int size, operations;
	scanf("%d %d", &size, &operations);

	Tree t(size);

	for (int i = 0; i < operations; ++i) {
		char c;
		scanf(" %c", &c);

		if(c == '+') {
			int index, value;
			scanf("%d %d", &index, &value);
			t.increment(index, value);
		} else {
			int firstN;
			scanf("%d", &firstN);

			printf("%lld\n", t.getTo(firstN));
		}

	}

}