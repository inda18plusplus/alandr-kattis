#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

struct Coord {
	int x;
	int y;
};

constexpr int GCD(int i1, int i2) {
	if(i1 == 0)
		return i2;
	if(i2 == 0)
		return i1;

	while(i2) {
		int remainder = i1 % i2;
		i1 = i2;
		i2 = remainder;
	}

	return i1;
}

std::size_t n;
std::vector<std::vector<char>> grid;

std::vector<Coord> letters;

int main() {

	scanf("%lu\n", &n);
	grid.resize(n, std::vector<char>(n, '.'));

	std::string line(n, ' ');
	for (int y = 0; y < n; ++y) {
		std::getline(std::cin, line);

		for (int x = 0; x < n; ++x) {
			grid[y][x] = line[x];

			if(line[x] != '.')
				letters.push_back({x, y});
		}
	}

	int count = 0;
	for(int i = 0; i < letters.size(); ++i) {

		auto& letter1 = letters[i];

		for (int j = i + 1; j < letters.size(); ++j) {
			auto& letter2 = letters[j];

			Coord diff = { letter2.x - letter1.x, letter2.y - letter1.y };
			int divisor = GCD(diff.x, diff.y);
			divisor = divisor < 0 ? -divisor : divisor;
			diff = { diff.x / divisor, diff.y / divisor };

			Coord check = { letter2.x + diff.x, letter2.y + diff.y };

			while (check.x < n && check.y < n) {
				if(grid[check.y][check.x] != '.') {
					++count;
				}

				check = { check.x + diff.x, check.y + diff.y };
			}
		}

	}

	printf("%d\n", count);

	return 0;

}