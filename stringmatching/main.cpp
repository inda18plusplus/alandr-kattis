#include <iostream>
#include <string>
#include <cstdio>

int main() {

	std::string needle, haystack;

	while(std::getline(std::cin, needle)) {

		std::getline(std::cin, haystack);

		std::size_t foundPos = 0;

		while ((foundPos = haystack.find(needle, foundPos)) != std::string::npos) {
			printf("%ld ", foundPos++);
		}

		printf("\n");

	}

}