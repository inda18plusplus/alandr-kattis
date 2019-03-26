#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <algorithm>

struct Point {
	constexpr Point(float x, float y) : x(x), y(y) {}
	float x, y;

	static constexpr float dist(const Point p1, const Point p2) {

		return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));

	}
};

std::tuple<float, Point, Point> bruteForce(const std::vector<Point>& points) {

	const auto size = points.size();

	float shortest = std::numeric_limits<float>::infinity();
	std::size_t shortest1, shortest2;
	for (std::size_t i = 0; i < size; ++i) {
		auto& p = points[i];
		for (std::size_t j =  i + 1; j < size; ++j) {

			float dist = Point::dist(p, points[j]);

			if(dist < shortest) {
				shortest = dist;
				shortest1 = i;
				shortest2 = j;
			}
		}
	}

	return {shortest, points[shortest1], points[shortest2]};

}
std::tuple<float, Point, Point> closestPair(const std::vector<Point> &pointsX, const std::vector<Point> &pointsY) {

	if(pointsX.size() <= 3) {
		return bruteForce(pointsX);
	}

	const std::size_t size = pointsX.size(), mid = size / 2 - 1;

	const Point& midPoint = pointsX[mid];

	std::vector<Point> pointsXLeft(pointsX.begin(), pointsX.begin() + mid + 1);
	std::vector<Point> pointsXRight(pointsX.begin() + mid + 1, pointsX.end());

	std::vector<Point> pointsYLeft;
	pointsYLeft.reserve(mid + 1);
	std::vector<Point> pointsYRight;
	pointsYRight.reserve(mid + 1);

	for(auto& p : pointsY) {
		if(p.x <= midPoint.x) {
			pointsYLeft .emplace_back(p);
		} else {
			pointsYRight.emplace_back(p);
		}
	}

	auto left = closestPair(pointsXLeft, pointsYLeft);
	auto right = closestPair(pointsXRight, pointsYRight);

	auto& smallest = (std::get<0>(left) < std::get<0>(right)) ? left : right;

	std::vector<Point> strip;
	for(auto& p : pointsY) {
		if(std::abs(midPoint.x - p.x) < std::get<0>(smallest))
			strip.push_back(p);
	}

	for (int i = 0; i < strip.size(); ++i) {
		for (int j = i + 1; j < strip.size(); ++j) {
			if(strip[j].y - strip[i].y < std::get<0>(smallest))
				break;

			if(float dist = Point::dist(strip[i], strip[j]); dist < std::get<0>(smallest)) {
				smallest = { dist, strip[i], strip[j] };
			}
		}
	}

	return smallest;

}

int main() {
	freopen("closestpair1.txt", "r", stdin);

	std::size_t n;
	std::vector<Point> pointsX;
	std::vector<Point> pointsY;

	std::cout.precision(2);

	for(;;) {
		scanf("%lu", &n);

		if(!n)
			break;

		pointsX.clear();
		pointsX.reserve(n);
		pointsY.clear();
		pointsY.reserve(n);

		float x, y;
		for (int i = 0; i < n; ++i) {
			scanf("%f %f", &x, &y);
			pointsX.emplace_back(x, y);
			pointsY.emplace_back(x, y);
		}

		std::sort(pointsX.begin(), pointsX.end(), [](auto& p1, auto& p2) -> bool{ return p1.x < p2.x; });
		std::sort(pointsY.begin(), pointsY.end(), [](auto& p1, auto& p2) -> bool{ return p1.y < p2.y; });

		auto [dis, p1, p2] = closestPair(pointsX, pointsY);

		printf("%.2f %.2f %.2f %.2f\n", p1.x, p1.y, p2.x, p2.y);

	}

	return 0;
}