#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

std::map<std::string, int> variables;

void parseExpression(const std::string& in) {

	std::stringstream ss(in);
	ss.ignore(5); //Eat "calc"

	std::vector<std::pair<char, std::string>> expressions;

	bool unknown = false;

	std::string name;
	ss >> name;
	expressions.emplace_back(std::make_pair('+', name));

	for(;;) {
		std::string c;
		ss >> c;

		if(c == "=")
			break;

		ss >> name;

		expressions.emplace_back(std::make_pair(c[0], name));
	}

	int total = 0;

	for(auto& p : expressions) {

		if(variables.find(p.second) == variables.end()) {
			unknown = true;
			break;
		}

		if(p.first == '+') {
			total += variables[p.second];
		} else {
			total -= variables[p.second];
		}

	}

	std::string outName;
	auto it = std::find_if(variables.begin(), variables.end(), [total](const auto& val)->bool{ return val.second == total; });
	if(it == variables.end()) {
		unknown = true;
	} else {
		outName = it->first;
	}

	std::cout << in.substr(5) << ' ';
	if(unknown) {
		std::cout << "unknown\n";
	} else {
		std::cout << outName << '\n';
	}

}

int main() {

	std::string row;
	while(std::getline(std::cin, row)) {

		std::string command;
		std::stringstream ss(row);

		std::getline(ss, command, ' ');

		if(command == "clear") {
			variables.clear();
		} else if(command == "def") {
			std::string name;
			int val;
			ss >> name >> val;

			variables[name] = val;
		} else if(command == "calc") {

			parseExpression(ss.str());

		}

	}

	return 0;
}