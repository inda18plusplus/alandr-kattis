//
// Created by lunar on 06/12/18.
//

#include "Tree.hpp"

#include <cstdio>
#include <vector>

struct Min {
	int operator()(int i1, int i2) {
		if(i1 == -1)
			return i2;
		if(i2 == -1)
			return i1;

		return i1 < i2 ? i1 : i2;
	}
};
struct LTE {

	int operator()(int i1, int i2) {
		if(i1 == -1)
			return false;
		if(i2 == -1)
			return true;

		return i1 <= i2;
	}

};

typedef Tree<int, -1, Min> Queue;

int main() {

	int queueSize, cartSize;
	scanf(" %d %d", &queueSize, &cartSize);

	std::vector<int> queueTime(queueSize, -1);
	Queue queue(queueSize);

	for (int i = 0; i < queueSize; ++i) {
		int sz;
		scanf(" %d", &sz);

		queue.set(i, sz);
	}

	int carts = 0;
	for (Queue::index_type front = queue.first(); front < queue.size(); front = queue.first(), ++carts) {
		int cart = queue.get(front);
		queueTime[front] = carts;

		queue.set(front, queue.empty());

		for(;;) {

			Queue::index_type lowest = queue.findLowest<LTE>();

			if(queue.get(lowest) > (cartSize - cart) || queue.first() == queue.size())
				break;

			cart += queue.get(lowest);
			queue.set(lowest, queue.empty());
			queueTime[lowest] = carts;

		}
	}

	for(auto i : queueTime) {
		printf("%d ", i);
	}

	return 0;

}