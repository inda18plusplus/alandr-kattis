//
// Created by lunar on 21/11/18.
//

#include "ray.hpp"


vec ray::at(int t) {

	return { o.x + d.x * t, o.y + d.y * t };

}