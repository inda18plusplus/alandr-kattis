#include <iostream>

int rankStars(int rank) {

	if(rank <= 10)
		return 5;

	if(rank <= 15)
		return 4;

	if(rank <= 20)
		return 3;

	return 2;

}

int main() {

	int stars = 0;
	int rank = 25;
	int wins = 0;

	std::string inStr;
	std::getline(std::cin, inStr);

	auto it = inStr.begin();

	while (it != inStr.end()) {

		if(*it == 'W') {

			++stars;
			++wins;

			if((wins >= 3) && (rank >= 6))
				++stars;

		} else {

			wins = 0;

			if(rank <= 20)
				--stars;
		}

		++it;

		if(stars == -1) {

			if((rank < 20) && (rank != 0)) {

				++rank;

				stars = rankStars(rank) - 1;

			} else {
				stars = 0;
			}

		} else if(stars > rankStars(rank)) {

			if(!rank)
				continue;

			stars -= rankStars(rank);
			--rank;
		}

	}

	if(rank) {
		std::cout << rank << '\n';
	} else {
		std::cout << "Legend\n";
	}

	return 0;
}