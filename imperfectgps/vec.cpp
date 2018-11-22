//
// Created by lunar on 21/11/18.
//

#include "vec.hpp"

#include <cmath>

float vec::dis(const vec &v) {

	return sqrtf(powf(x - v.x, 2) + powf(y - v.y, 2));

}