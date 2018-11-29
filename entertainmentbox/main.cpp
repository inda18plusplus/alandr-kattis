//
// Created by lunar on 28/11/18.
//

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

typedef std::pair<int, int> Programme; //[start time, end time)

int main() {

	int numProgrammes, concurrent;

	std::cin >> numProgrammes >> concurrent;

	std::vector<Programme> programmes(numProgrammes, Programme{});

	for (int i = 0; i < numProgrammes; ++i) {
		Programme p;
		std::cin >> p.first >> p.second;
		programmes[i] = p;
	}

	std::sort(programmes.begin(), programmes.end(), [] (const Programme& p1, const Programme& p2)->bool {
		return p1.second < p2.second;
	});

	int count = 0;
	std::multiset<int> slots;
	for (int i = 0; i < concurrent; ++i) {
		slots.insert(0);
	}

	for(const auto& p : programmes) {
		const auto& [start, end] = p;

		auto it = slots.upper_bound(start);
		if(it != slots.begin()) {
			--it;
			slots.erase(it);
			slots.insert(end);
			++count;
		}
	}

	std::cout << count;

}