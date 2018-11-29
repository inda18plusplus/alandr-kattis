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

std::map<unsigned int, double> memory;

double solve(unsigned int chosen, int operation) {

	if(operation >= numBonds)
		return 1.0;

	if(memory.count(chosen))
		return memory[chosen];

	double ret = 0.0;

	for (int i = 0; i < numBonds; ++i) {
		if(!(chosen & (1 << i))) {
			auto tmp = chosen;
			tmp |= (1 << i);
			double answer = bonds[i][operation] * solve(tmp, operation + 1);
			if(answer > ret)
				ret = answer;
		}
	}

	memory[chosen] = ret;
	return ret;

}

double solve() {

	return solve(0, 0);

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