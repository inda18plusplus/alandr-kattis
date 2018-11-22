//
// Created by lunar on 22/11/18.
//

#ifndef KATTIS9_QUANTUM_HPP
#define KATTIS9_QUANTUM_HPP

#include <string>

class Operation {

	unsigned int _flip = 0u;
	unsigned int _clear = 0u;
	unsigned int _set = 0u;

	unsigned int _cost;

public:
	Operation(const std::string &str, unsigned int cost);

	unsigned int apply(unsigned int num) const;
	unsigned int cost() const { return _cost; }

};


#endif //KATTIS9_QUANTUM_HPP
