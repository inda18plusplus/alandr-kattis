#include <cstdio>
#include <vector>
#include <initializer_list>
#include "MinCostMaxFlow.h"


typedef std::pair<int, int> Coord;

const int big = 100'000;

constexpr bool isEven(int i) {
	return !(i & 1);
}
constexpr bool isEven(Coord c) {
	return isEven(c.first + c.second);
}

std::vector<int> board;

int main() {

	int sideLen, numDominoes;
	scanf("%d %d", &sideLen, &numDominoes);
	const int boardSize = sideLen*sideLen;

	board.resize(boardSize, 0);

	int tileSum = 0;
	for (int i = 0; i < boardSize; ++i) {
		scanf("%d", &board[i]);
		tileSum += board[i];
	}

	MCMF flow(boardSize + 3);

	const int limiter = boardSize;
	const int source = boardSize + 1;
	const int target = boardSize + 2;

	for (int y = 0; y < sideLen; ++y) {
		for (int x = 0; x < sideLen; ++x) {
			const Coord c(x, y);
			const int index = c.first + c.second * sideLen;

			if(isEven(c)) {
				flow.addEdge(limiter, index, 1, 0);

				for (auto offset : { Coord{0, -1}, {0, 1}, {-1, 0}, {1,0} }) {
					Coord newCoord(c.first + offset.first, c.second + offset.second);
					const int newIndex = newCoord.first + newCoord.second * sideLen;

					if(newCoord.first >= 0 && newCoord.first < sideLen && newCoord.second >= 0 && newCoord.second < sideLen)
						flow.addEdge(index, newIndex, 1, big - ( board[index] + board[newIndex] ));
				}
			} else {
				flow.addEdge(index, target, 1, 0);
			}
		}
	}

	flow.addEdge(source, limiter, numDominoes, 0);

	auto res = flow.maxflow(boardSize + 1, boardSize + 2);

	int cost = numDominoes * big - res.second;

	printf("%d\n", tileSum - cost);

}