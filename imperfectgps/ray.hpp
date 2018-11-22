//
// Created by lunar on 21/11/18.
//

#ifndef KATTIS9_RAY_H
#define KATTIS9_RAY_H

#include "vec.hpp"

struct ray {
	vec o;
	vec d;

	vec at(int t);
};

#endif //KATTIS9_RAY_H
