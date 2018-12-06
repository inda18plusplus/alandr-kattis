//
// Created by lunar on 28/11/18.
//
#include <cstdio>
#include <stack>
#include <queue>

int main() {

	freopen("guessthedatastructure.txt", "r", stdin);

	int operations;

	while(scanf(" %d", &operations) != EOF) {

		bool canStack = true;
		bool canQueue = true;
		bool canPrioQ = true;

		std::stack<int> stack;
		std::queue<int> queue;
		std::priority_queue<int> prioQ;

		for (int i = 0; i < operations; ++i) {
			int operation, value;
			scanf(" %d %d", &operation, &value);

			if(operation == 1) {
				stack.push(value);
				queue.push(value);
				prioQ.push(value);
			} else {

				if(stack.empty()) {
					canStack = false;
					canQueue = false;
					canPrioQ = false;
					break;
				}

				int out = stack.top();
				stack.pop();

				if(out != value)
					canStack = false;

				out = queue.front();
				queue.pop();

				if(out != value)
					canQueue = false;

				out = prioQ.top();
				prioQ.pop();

				if(out != value)
					canPrioQ = false;
			}

		}

		int sum = canStack + canQueue + canPrioQ;

		if(sum == 0) {
			printf("impossible\n");
		} else if(sum > 1) {
			printf("not sure\n");
		} else {

			if(canStack)
				printf("stack\n");
			if(canQueue)
				printf("queue\n");
			if(canPrioQ)
				printf("priority queue\n");

		}

	}

}