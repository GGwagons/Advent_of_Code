#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

bool isSafeReport(const std::string &report) {
    std::istringstream iss(report);
    std::vector<int> levels;
    int num;
    while (iss >> num) {
        levels.push_back(num);
    }
    int n = levels.size();
    if (n <= 1) {
        return true;
    }
    bool increasing = true, decreasing = true;
    for (int i = 1; i < n; ++i) {
        int diff = levels[i] - levels[i - 1];
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }
        if (diff > 0) {
            decreasing = false;
        }
		else if (diff < 0) {
            increasing = false;
        }
    }
    return increasing || decreasing;
}

bool canBecomeSafeByRemovingOne(const std::string &report) {
    std::istringstream iss(report);
    std::vector<int> levels;
    int num;
    while (iss >> num) {
        levels.push_back(num);
    }
    int n = levels.size();
    if (n <= 2) {
        return true;
    }
    for (int i = 0; i < n; ++i) {
        std::vector<int> modifiedLevels;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                modifiedLevels.push_back(levels[j]);
            }
        }
        std::ostringstream oss;
        for (size_t k = 0; k < modifiedLevels.size(); ++k) {
            if (k > 0) {
                oss << " ";
            }
            oss << modifiedLevels[k];
        }
        if (isSafeReport(oss.str())) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }
    std::string line;
    int safeCount = 0;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            if (isSafeReport(line) || canBecomeSafeByRemovingOne(line)) {
                ++safeCount;
            }
        }
    }
    inputFile.close();
    std::cout << "Number of safe reports: " << safeCount << std::endl;
    return 0;
}
