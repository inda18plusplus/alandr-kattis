//
// Created by lunar on 28/11/18.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

	int cases;
	std::cin >> cases;

	std::vector<long> v1;
	std::vector<long> v2;

	for (int i = 0; i < cases; ++i) {

		int vecSize;
		std::cin >> vecSize;

		v1.resize(vecSize);
		v2.resize(vecSize);

		for (int j = 0; j < vecSize; ++j)
			std::cin >> v1[j];
		for (int j = 0; j < vecSize; ++j)
			std::cin >> v2[j];

		std::sort(v1.begin(), v1.end(), std::less<>());
		std::sort(v2.begin(), v2.end(), std::greater<>());

		long long result = 0;

		for (int j = 0; j < vecSize; ++j) {
			result += v1[j] * v2[j];
		}

		printf("Case #%d: %lld\n", i + 1, result);

	}

	return 0;

}