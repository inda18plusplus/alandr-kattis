//
// Created by lunar on 28/11/18.
//
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

int numBonds;
typedef double bond[20];
bond bonds[20];

std::map<std::vector<bool>, double> memory;

double solve(const std::vector<bool>& chosen, int operation) {

	if(operation >= numBonds)
		return 1.0;

	if(memory.count(chosen))
		return memory[chosen];

	double ret = 0.0;

	for (int i = 0; i < numBonds; ++i) {
		if(!chosen[i]) {
			auto tmp = chosen;
			tmp[i] = true;
			double answer = bonds[i][operation] * solve(tmp, operation + 1);
			if(answer > ret)
				ret = answer;
		}
	}

	memory[chosen] = ret;
	return ret;

}

double solve() {

	std::vector<bool> in(numBonds, false);
	return solve(in, 0);

}

int main() {

	std::cin >> numBonds;

	for (int i = 0; i < numBonds; ++i) {
		for (int j = 0; j < numBonds; ++j) {
			std::cin >> bonds[i][j];
			bonds[i][j] /= 100;
		}
	}

	std::cout << std::setprecision(10) << solve() * 100;

	return 0;

}