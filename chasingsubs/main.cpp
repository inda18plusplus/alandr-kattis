#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

bool isEqual(const std::vector<std::size_t> &text, std::size_t startPos, const std::vector<std::size_t> &decr) {

	for (int i = 0; i < decr.size(); ++i) {
		if(decr[i] != text[i + startPos]) {

			if(decr[i] == std::string::npos && text[i + startPos] >= (decr.size() - i)) {
				continue;
			}

			return false;
		}
	}

	return true;

}

int main() {

	std::string text;
	std::string decrypted;

	std::getline(std::cin, text);
	std::getline(std::cin, decrypted);

	std::vector<std::size_t> nextDisText(text.length(), 0);
	for (std::size_t i = 0; i < text.length(); ++i) {
		auto pos = text.find(text[i], i + 1);

		if(pos != std::string::npos)
			pos -= i;

		nextDisText[i] = pos;
	}

	std::vector<std::size_t> nextDistDecr(decrypted.length(), 0);
	for (std::size_t i = 0; i < decrypted.length(); ++i) {
		auto pos = decrypted.find(decrypted[i], i + 1);

		if(pos != std::string::npos)
			pos -= i;

		nextDistDecr[i] = pos;
	}

	int foundPos = 0;
	int counter = 0;

	for (int i = 0; i <= text.length() - decrypted.length(); ++i) {

		if(isEqual(nextDisText, i, nextDistDecr)) {
			foundPos = i;
			++counter;
		}

	}

	if(counter == 1) {
		std::cout << text.substr(foundPos, decrypted.length()) << '\n';
	} else {
		printf("%d\n", counter);
	}

}