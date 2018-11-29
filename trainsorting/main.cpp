//
// Created by lunar on 28/11/18.
//

#include <chrono>

#include <fstream>
#include <iostream>
#include <map>
#include <cstdint>
#include <vector>

typedef std::vector<int16_t> trainLine;

struct SolveState {

	trainLine::size_type index;
	int16_t front, back;

	bool operator<(const SolveState& other) const {
		if(index < other.index) return true;
		if(other.index < index) return false;

		if(front < other.front) return true;
		if(other.front < front) return false;

		return back < other.back;

		//return std::tie(index, front, back) < std::tie(other.index, other.front, other.back);
	}

};

trainLine incoming;
std::map<SolveState, int> mem;

int solveFor(SolveState state) {

	if(state.index == incoming.size())
		return 0;

	if(mem.count(state))
		return mem[state];

	int longestSub = 0; //The longest train further down the tree

	if(state.front < incoming[state.index]) { //Stick it to the front
		SolveState newState {state.index + 1, incoming[state.index], state.back};
		if(newState.back == -1) {
			newState.back = newState.front;
		}
		longestSub = solveFor(newState) + 1;
	}

	if(state.back > incoming[state.index]) //Stick it to the back
		longestSub = std::max(
				longestSub,
				solveFor({ state.index + 1, state.front, incoming[state.index] }) + 1
		);

	longestSub = std::max( //Ignore it
			longestSub,
			solveFor({ state.index + 1, state.front, state.back })
	);

	mem[state] = longestSub;

	return longestSub;

}

int solve() {

	return solveFor(SolveState{0, -1, -1});

}

int main() {

	freopen("trainsorting.txt", "r", stdin);

	int numCars;
	std::cin >> numCars;

	incoming.resize(numCars);

	for (int i = 0; i < numCars; ++i) {
		std::cin >> incoming[i];
	}

	auto start = std::chrono::system_clock::now();
	std::cout << solve();
	auto end = std::chrono::system_clock::now();

	std::cerr << "Took " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " seconds\n";

}