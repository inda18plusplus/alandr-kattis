//
// Created by lunar on 17/01/19.
//

#include <cstdio>
#include <vector>
#include <queue>

const int INFINITY = 1 << 20;

int h, w;
int map[102][102];

std::pair<int, int> prisoners[2] = {{}, {}};

const std::pair<int, int> dirs[] = {
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
};

bool isValidPos(std::pair<int, int>& pos) {
	return !(pos.first < 0 || pos.first >= w + 2 || pos.second < 0 || pos.second >= h + 2);
}

void BFS(std::pair<int, int> startPos, int (&DisMap)[102][102]) {

	for (int y = 0; y <= h + 1; ++y) {
		for (int x = 0; x <= w + 1; ++x) {
			DisMap[y][x] = INFINITY;
		}
	}

	std::queue<std::pair<std::pair<int, int>, int>> toSearch;
	toSearch.emplace(startPos, 0);

	while(!toSearch.empty()) {
		const auto state = toSearch.front();
		const auto& cost = state.second;
		const auto& pos = state.first;

		if(cost < DisMap[pos.second][pos.first]) {
			DisMap[pos.second][pos.first] = cost;

			for(auto& dir : dirs) {

				auto newPos = pos;
				newPos.first += dir.first;
				newPos.second += dir.second;

				if(isValidPos(newPos)) {
					switch(map[newPos.second][newPos.first]) {

						case '.':
						case '$':
							toSearch.emplace(newPos, cost);
							break;
						case '#':
							toSearch.emplace(newPos, cost + 1);
							break;
						default:
							break;

					}
				}

			}

		}

		toSearch.pop();

	}

}

void solve() {

	int OutsideDisMap[102][102];
	int Prisoner1Map[102][102];
	int Prisoner2Map[102][102];

	BFS({0,0}, OutsideDisMap);
	BFS(prisoners[0], Prisoner1Map);
	BFS(prisoners[1], Prisoner2Map);

	int bestCombination = INFINITY;

	for (int x = 0; x <= w + 1; ++x) {
		for (int y = 0; y <= h + 1; ++y) {
			int pathLen = OutsideDisMap[y][x] + Prisoner1Map[y][x] + Prisoner2Map[y][x];

			if(map[y][x] == '#')
				pathLen -= 2;

			bestCombination = std::min(bestCombination, pathLen);
		}
	}

	printf("%d\n", bestCombination);

}

int main(){

	int cases;
	scanf("%d", &cases);

	for (int i = 0; i < cases; ++i) {

		prisoners[0] = {};

		scanf("%d %d\n", &h, &w);

		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int c = getchar();

				if(c == '$') {
					if(prisoners[0] == std::pair<int, int>(0,0))
						prisoners[0] = {x + 1, y + 1};
					else
						prisoners[1] = {x + 1, y + 1};
				}

				map[y + 1][x + 1] = c;
			}
			getchar(); //Eat the \n
		}
		for (int x = 0; x <= w + 1; ++x) {
			map[0][x] = '.';
			map[h + 1][x] = '.';
		}
		for (int y = 1; y <= h; ++y) {
			map[y][0] = '.';
			map[y][w + 1] = '.';
		}

		solve();

	}

}