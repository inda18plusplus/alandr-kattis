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

	std::vector<std::pair<unsigned int, int>> costs;
	costs.resize(_searchSpace);

	std::list<std::pair<unsigned int, int>*> toSearch; //Value, cost

	for(int i = 0; i < costs.size(); ++i) {
		costs[i] = {i, i == from ? 0 : -1};
		toSearch.emplace_back(&costs[i]);
	}

	std::pair<unsigned int, int>* target = &costs[to];

	toSearch.sort(comparator{});

	while(!toSearch.empty()) {

		auto& p = toSearch.front();

		if(p->second == -1) {
			return costs[to].second;
		}

		if(target->second == -1 || p->second <= target->second) {
			for (auto &op : _ops) {
				unsigned int val = op.apply(p->first);

				int cost = p->second + op.cost();

				if (cost < costs[val].second || costs[val].second == -1) {
					auto *pair = &costs[val];
					toSearch.remove(pair);

					pair->second = cost;

					auto insertpoint = std::find_if(toSearch.begin(), toSearch.end(),
						[pair](std::pair<unsigned int, int> *p) {
						    if (p->second == -1)
						        return true;
						    return pair->second < p->second;
						});
					toSearch.insert(insertpoint, pair);
				}
			}
		}

		toSearch.erase(toSearch.begin());

	}

	return costs[to].second;

}