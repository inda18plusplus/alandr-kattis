//
// Created by lunar on 22/11/18.
//

#ifndef KATTIS9_SEARCH_HPP
#define KATTIS9_SEARCH_HPP

#include <vector>
#include <unordered_set>

#include "Operation.hpp"

class Search {

	int _searchSpace = 0;

	const std::vector<Operation>& _ops;

public:
	Search(int wordLen, std::vector<Operation>& ops);

	int find(unsigned int from, unsigned int to);

	struct comparator {
		bool operator() (const std::pair<unsigned int, int>* a, const std::pair<unsigned int, int>* b) {
			if(a->second == -1)
				return false;
			if(b->second == -1)
				return true;

			return a->second < b->second;
		}
	};

};


#endif //KATTIS9_SEARCH_HPP
