#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iterator>
#include <fstream>

template <typename T>
typename T::iterator easyFind(T &con, std::string x) {
	typename T::iterator it = find(con.begin(), con.end(), x);
	return it;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	std::vector<std::string> vec;
	std::string line;
	while (std::getline(file, line)) {
		vec.push_back(line);
	}
	std::string x = "m";
	std::cout << *easyFind(vec, x) << std::endl;
	return 0;
}
