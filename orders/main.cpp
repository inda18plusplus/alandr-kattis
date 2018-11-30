//
// Created by lunar on 28/11/18.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>

typedef std::pair<int, int> item;
std::vector<item> items; //index, price

std::vector<int> orders;

void solve() {

	int highestOrder = 0;
	for (int& order : orders) {
		if(order > highestOrder)
			highestOrder = order;
	}

	std::map<int, std::map<int, int>> mem;
	std::set<int> duplicates;
	mem[0] = {};

	for (int i = 0; i <= highestOrder; ++i) {
		if(!mem.count(i))
			continue;

		for(int j = 0; j < items.size(); ++j) {

			auto& item = items[j];
			int result = i + item.second;

			auto path = mem[i];
			path[j]++;

			if(duplicates.count(i))
				duplicates.insert(result);

			if(mem.count(result)) {
				auto oldPath = mem[result];
				if(path != oldPath)
					duplicates.insert(result);
			}

			mem[result] = path;

		}
	}

	for (auto& order : orders) {

		if(!mem.count(order)) {
			std::cout << "Impossible\n";
			continue;
		}

		if(duplicates.count(order)) {
			std::cout << "Ambiguous\n";
			continue;
		}

		for(auto& p : mem[order]) {
			for (int i = 0; i < p.second; ++i) {
				std::cout << p.first + 1 << ' ';
			}
		}
		std::cout << '\n';

	}

}

int main() {

	int numItems;
	std::cin >> numItems;

	items.resize(numItems);
	for (int i = 0; i < numItems; ++i) {
		int price;
		std::cin >> price;
		items[i] = {i + 1, price};
	}

	int numOrders;
	std::cin >> numOrders;
	orders.resize(numOrders);

	for(auto& i : orders) {
		std::cin >> i;
	}

	solve();

	return 0;

}