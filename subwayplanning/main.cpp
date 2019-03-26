#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const double PI = acos(-1);
const double error_margin = 1e-9;

struct Place {
	double angle;
	double dis;

	double deviation;
};

bool inRangeOf(Place place, double angle) {
	return
}

double angleLoop(double in) {
	if(in >= 2*PI)
		return in - 2*PI;

	return in;
}

int main() {

	int numSets;
	scanf("%d", &numSets);

	for (int setNum = 0; setNum < numSets; ++setNum) {

		std::vector<Place> places;

		int numStations, range;
		scanf("%d %d", &numStations, &range);

		for (int i = 0; i < numStations; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);

			double dis = sqrt(x*x + y*y);
			if((dis - error_margin) < range)
				continue;

			double angle = atan2(y, x);
			angle = angle < 0 ? 2*PI - angle : angle;
			double deltaA = range == 0 ? 0 : atan((double)range / dis);

			places.push_back({angle, dis, deltaA});
		}

		std::sort(places.begin(), places.end(), [](const Place& p1, const Place& p2){ return angleLoop(p1.angle - p1.deviation) < angleLoop(p2.angle - p2.deviation); });

		int min = 0;
		for (int i = 0; i < places.size(); ++i) {
			std::vector<bool> placeVisited(places.size(), false);

			std::rotate(places.begin(), places.begin() + 1, places.end());
		}

	}

}
