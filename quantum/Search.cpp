//
// Created by lunar on 22/11/18.
//

#include "Search.hpp"

#include <algorithm>
#include <climits>
#include <queue>
#include <list>

Search::Search(int wordLen, std::vector<Operation> &ops) : _searchSpace(1u << (wordLen)), _ops(ops) {

	std::sort(ops.begin(), ops.end(), [](const Operation& op1, const Operation& op2){
		return op1.cost() < op2.cost();
	});

}

int Search::find(unsigned int from, unsigned int to) {

	typedef std::pair<int, unsigned int> costVal;

	std::vector<int> costs(_searchSpace, -1);
	std::priority_queue<costVal, std::vector<costVal>,  std::greater<costVal>> toSearch; //Value, cost

	costs[from] = 0;
	toSearch.push({0, from});

	while(!toSearch.empty()) {

		auto p = toSearch.top();

		for (auto& op : _ops) {

			int cost = p.first + op.cost();

			unsigned int res = op.apply(p.second);

			if(res == to) {
				return cost;
			}

			if(costs[res] == -1 || cost <= costs[res]) {
				costs[res] = cost;
				toSearch.push({cost, res});
			}

		}

		toSearch.pop();

	}

	return costs[to];

}