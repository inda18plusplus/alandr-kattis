//
// Created by lunar on 13/01/19.
//

#include <algorithm>
#include <cstdio>
#include <vector>

int graphSize, numEdges;

std::vector<std::pair<int, std::pair<int, int>>> edges; //weight, node1, node2
std::vector<std::pair<int, int>> tree;

std::vector<int> DJSet;

int root(int id) {
	while(DJSet[id] != id) {
		DJSet[id] = DJSet[DJSet[id]];
		id = DJSet[id];
	}

	return id;
}
void createUnion(int i1, int i2) {
	int p = root(i1);
	int q = root(i2);

	DJSet[p] = DJSet[q];
}
bool find(int i1, int i2) {
	return root(i1) == root(i2);
}

void initSet() {

	DJSet.resize(graphSize);
	for (int i = 0; i < graphSize; ++i) {
		DJSet[i] = i;
	}

}
void init() {

	initSet();

	edges.clear();
	edges.reserve(numEdges);

	tree.clear();

}

int calcMinSpanTree() {

	std::sort(edges.begin(), edges.end());

	int cost = 0;

	for (int i = 0; i < numEdges && tree.size() < graphSize - 1; ++i) {
		const auto& edge = edges[i];

		const auto weight = edge.first;

		const auto n1 = edge.second.first;
		const auto n2 = edge.second.second;

		if(!find(n1, n2)) {

			cost += weight;
			createUnion(n1, n2);

			tree.emplace_back(edge.second);

			if(tree.size() == graphSize - 1)
				int j = 0;

		}
	}

	return cost;

}

int main() {

	for(;;) {

		scanf("%d %d", &graphSize, &numEdges);

		if(graphSize == 0)
			break;

		init();

		for (int i = 0; i < numEdges; ++i) {
			int from, to, weight;
			scanf("%d %d %d", &from, &to, &weight);

			edges.emplace_back(weight, from < to ? std::make_pair(from, to) : std::make_pair(to, from));
		}

		int cost = calcMinSpanTree();

		if(tree.size() == graphSize - 1) {

			std::sort(tree.begin(), tree.end());

			printf("%d\n", cost);
			for(auto& p : tree) {
				printf("%d %d\n", p.first, p.second);
			}

		} else {
			printf("Impossible\n");
		}

	}

}