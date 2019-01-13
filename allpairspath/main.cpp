#include <cstdio>
#include <vector>
#include <limits>
#include <queue>

constexpr const auto Infinity = std::numeric_limits<double>::infinity();

typedef double EdgeLen;

void calcDists(std::vector<EdgeLen>& edges, unsigned int numNodes) {

	for (int k = 0; k < numNodes; ++k) {
		for (int i = 0; i < numNodes; ++i) {
			for (int j = 0; j < numNodes; ++j) {

				EdgeLen& val = edges[i*numNodes + j];
				EdgeLen newVal = edges[i*numNodes + k] + edges[k*numNodes + j];

				if(newVal < val)
					val = newVal;

			}
		}
	}

}

void fillNegInf(std::vector<EdgeLen>& edges, unsigned int numNodes) {

	for(int i = 0; i < numNodes; i++)
		for(int j = 0; j < numNodes; j++)
			for(int k = 0; edges[i*numNodes + j] != -Infinity && k < numNodes; k++)
				if(edges[i*numNodes + k] != Infinity &&
				   edges[k*numNodes + j] != Infinity &&
				   edges[k*numNodes + k] < 0)

					edges[i*numNodes + j] = -Infinity;

}

int main() {

	unsigned int numNodes, numEdges, numQueries;

	std::vector<EdgeLen> edges;

	for(;;) {

		scanf("%d %d %d", &numNodes, &numEdges, &numQueries);

		if(numNodes == 0)
			break;

		edges.resize(numNodes * numNodes);
		std::fill(edges.begin(), edges.end(), Infinity);

		for (int i = 0; i < numNodes; ++i)
			edges[i * numNodes + i] = 0;

		for (int i = 0; i < numEdges; ++i) {
			int orig, dest, weight;
			scanf("%d %d %d", &orig, &dest, &weight);

			double& oldVal = edges[orig*numNodes + dest];

			if(oldVal > weight) {
				oldVal = weight;
			}
		}

		calcDists(edges, numNodes);

		fillNegInf(edges, numNodes);

		for (int i = 0; i < numQueries; ++i) {
			int queryFrom, queryTo;
			scanf("%d %d", &queryFrom, &queryTo);

			if(edges[queryFrom*numNodes + queryFrom] == -Infinity) {
				printf("-Infinity\n");
			} else if(edges[queryFrom * numNodes + queryTo] == Infinity) {
				printf("Impossible\n");
			} else {
				double val = edges[queryFrom*numNodes + queryTo];
				printf("%d\n", (int)val);
			}
		}

		printf("\n");

	}

}