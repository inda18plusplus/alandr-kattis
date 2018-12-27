#include <cstdio>
#include <vector>
#include <limits>
#include <queue>

typedef std::pair<unsigned int, unsigned int> Edge; //to, weight

void calcDists(std::vector<std::vector<Edge>>& edges, std::vector<unsigned int>& dist, unsigned int start) {

	typedef std::pair<unsigned int, unsigned int> searchNode; //Dist, id
	std::priority_queue<searchNode, std::vector<searchNode>, std::greater<>> search;

	search.push({0, start});
	dist[start] = 0;

	while(!search.empty()) {

		auto node = search.top();
		search.pop();

		for(auto& edge : edges[node.second]) {
			unsigned int newDist = node.first + edge.second;

			if(newDist < dist[edge.first]) {
				dist[edge.first] = newDist;
				search.emplace(newDist, edge.first);
			}
		}

	}

}

int main() {

	unsigned int numNodes, numEdges, numQueries, startIndex;

	std::vector<std::vector<Edge>> edges;
	std::vector<unsigned int> dist;

	for(;;) {

		scanf("%d %d %d %d", &numNodes, &numEdges, &numQueries, &startIndex) != EOF;

		if(numNodes == 0)
			break;

		edges.clear();
		edges.resize(numNodes);

		dist.resize(numNodes);
		std::fill(dist.begin(), dist.end(), std::numeric_limits<unsigned int>::max());

		for (int i = 0; i < numEdges; ++i) {
			unsigned int orig, dest, weight;
			scanf("%d %d %d", &orig, &dest, &weight);

			edges[orig].emplace_back(dest, weight);
		}

		calcDists(edges, dist, startIndex);

		for (int i = 0; i < numQueries; ++i) {
			int query;
			scanf("%d", &query);

			if(dist[query] == std::numeric_limits<unsigned int>::max()) {
				printf("Impossible\n");
			} else {
				printf("%d\n", dist[query]);
			}
		}

		printf("\n");

	}

}