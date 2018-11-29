#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

#include "ray.hpp"

int main() {

	std::ifstream inf("imperfectgps.txt");
	std::istream& in = inf;

	std::vector<std::pair<ray, int>> path;

	int lines;
	int interval;

	in >> lines >> interval;

	for (int i = 0; i < lines; ++i) {

		float x,y;
		int t;

		in >> x >> y >> t;

		path.emplace_back(std::make_pair(ray{{x,y}, {0, 0}}, t));

	}

	double trueDis = 0;
	for (auto it = path.begin(); it != path.end() - 1; ++it) {

		vec orig = it->first.o;
		vec dest = (it + 1)->first.o;

		trueDis += orig.dis(dest);

		vec diff = {dest.x - orig.x, dest.y - orig.y};

		it->first.d = diff / ((it + 1)->second - it->second);

	}

	double total = 0;
	vec pos = {0, 0};

	for (int time = interval; time < path.rbegin()->second; time += interval) {

		auto currRay = std::find_if(path.begin(), path.end(), [time](const std::pair<ray, int>& p){
			return p.second > time;
		}) - 1;

		auto newPos = currRay->first.at(time - currRay->second);

		total += newPos.dis(pos);

		pos = newPos;

	}

	total += pos.dis(path.rbegin()->first.o);

	std::cout << std::setprecision(12) << (1.0f - (total / trueDis)) * 100.f << '\n';

	return 0;
}