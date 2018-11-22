#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Operation.hpp"
#include "Search.hpp"

unsigned int fromBinaryStr(const std::string& str) {

	unsigned int ret = 0;
	for (int i = 0; i < str.length(); ++i) {
		ret |= ((str[i] - '0') << (str.length() - i - 1));
	}

	return ret;

}

int main() {

	//std::ifstream inf("quantum.txt");
	std::istream& in = std::cin;//inf;

	int cases;
	in >> cases;

	for (int i = 0; i < cases; ++i) {

		std::vector<Operation> operations;

		int wordLen;
		int nOperations, nWords;

		in >> wordLen >> nOperations >> nWords;

		operations.reserve(nOperations);

		for (int j = 0; j < nOperations; ++j) {
			std::string operation;
			int cost;

			in >> operation >> cost;

			operations.emplace_back(Operation(operation, cost));
		}

		Search s(wordLen, operations);

		for (int j = 0; j < nWords; ++j) {

			std::string sFrom, sTo;
			in >> sFrom >> sTo;

			int from = fromBinaryStr(sFrom);
			int to = fromBinaryStr(sTo);

			int cost = s.find(from, to);

			if(cost == -1) {
				std::cout << "NP";
			} else {
				std::cout << cost;
			}

			if(j < (nWords - 1)) {
				std::cout << ' ' << std::flush;
			}

		}

		std::cout << '\n';

	}

	return 0;

}