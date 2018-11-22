//
// Created by lunar on 21/11/18.
//

#ifndef KATTIS9_VEC_H
#define KATTIS9_VEC_H

struct vec {
	float x;
	float y;

	vec operator/(float f) { return { x/f, y/f }; }

	float dis(const vec& v);
};

#endif //KATTIS9_VEC_H
