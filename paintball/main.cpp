#include <cstdio>
#include <vector>

std::vector<std::vector<int>> sight;

int main() {

	int numPlayers, numLinks;
	scanf("%d %d", &numPlayers, &numLinks);
	sight.resize(numPlayers);

	for (int i = 0; i < numLinks; ++i) {
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		sight[p1 - 1].emplace_back(p2 - 1);
		sight[p2 - 1].emplace_back(p1 - 1);
	}

}