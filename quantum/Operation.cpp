//
// Created by lunar on 22/11/18.
//

#include "Operation.hpp"

Operation::Operation(const std::string &str, unsigned int cost) : _cost(cost) {

	for (unsigned int i = 0; i < str.length(); ++i) {

		switch (str[i]) {

			case 'N':
				break;

			case 'F':
				_flip |= 1u << (str.length() - i - 1);
				break;

			case 'S':
				_set |= 1u << (str.length() - i - 1);
				break;

			case 'C':
				_clear |= 1u << (str.length() - i - 1);

		}

	}

}

unsigned int Operation::apply(unsigned int num) const {

	num ^= _flip;
	num &= ~_clear;
	num |= _set;

	return num;

}