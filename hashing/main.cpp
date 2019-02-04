#include <string>
#include <vector>
#include <iostream>

typedef unsigned __int128 ull;

const ull p = 257;
const ull mod = 1'000'000'000 + 7;

std::string input;
std::vector<ull> hashes;
std::vector<ull> pows;

ull hash(size_t from, size_t to) {

	return (hashes[to] - hashes[from] * pows[to - from]) % mod;

}

int main() {

	std::getline(std::cin, input);
	hashes.resize(input.length() + 1);
	hashes[0] = 0;

	pows.resize(input.length());
	ull pow = 1;
	for (auto& i : pows) {
		i = pow;
		pow *= p;
		pow %= mod;
	}

	hashes[0] = 0;
	for (int i = 1; i <= input.length(); ++i) {
		hashes[i] = p*hashes[i - 1] + (input[i - 1] - 'a' + 1) % mod;
	}

	int numQueries;
	scanf("%d", &numQueries);

	for (int i = 0; i < numQueries; ++i) {
		size_t from, to;
		scanf("%lu %lu", &from, &to);
		printf("%llu\n", hash(from, to));
	}

}