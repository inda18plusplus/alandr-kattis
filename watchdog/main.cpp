#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

struct Coord {
	int x;
	int y;
};

int S, H;

std::vector<Coord> hatches;
std::vector<std::vector<bool>> hasHatch;

float dis(const Coord& c1, const Coord& c2) {
	return sqrtf(powf(c1.x - c2.x, 2) + powf(c1.y - c2.y, 2));
}

int main() {

	int line = 1;

	int cases;
	scanf("%d", &cases);

	for (int caseN = 0; caseN < cases; ++caseN) {

		scanf("%d %d", &S, &H);

		hatches.clear();
		hatches.resize(H, {0,0});
		hasHatch.clear();
		hasHatch.resize(S, std::vector<bool>(S, false));

		for (int i = 0; i < H; ++i) {
			line++;
			scanf("%d %d", &hatches[i].x, &hatches[i].y);
			hasHatch[hatches[i].y][hatches[i].x] = true;
		}

		bool found = false;
		for (int x = 1; x < S && !found; ++x) {
			for (int y = 1; y < S && !found; ++y) {
				if(hasHatch[y][x])
					continue;

				int leashLen = std::min({x, y, S-x, S-y});

				bool allIn = true;
				for(auto& hatch : hatches) {
					if(dis({x, y}, hatch) > leashLen) {
						allIn = false;
						break;
					}
				}

				if(allIn) {
					found = true;
					printf("%d %d\n", x, y);
				}

			}
		}

		if(!found) {
			printf("poodle\n");
		}

	}

	return 0;

}