#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

bool isSafeReport(const std::string &report) {
    std::istringstream iss(report);
    std::vector<int> levels;
    int num;
    while (iss >> num) {
        levels.push_back(num);
    }
    int n = levels.size();
    if (n < 2) {
        return true;
    }
    bool isIncreasing = true;
    bool isDecreasing = true;
    for (int i = 1; i < n; ++i) {
        int diff = levels[i] - levels[i - 1];
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }
        if (diff > 0) {
            isDecreasing = false;
        }
		else if (diff < 0) {
            isIncreasing = false;
        }
    }
    return isIncreasing || isDecreasing;
}

int countSafeReports(const std::vector<std::string> &reports) {
    int safeCount = 0;
    for (const std::string &report : reports) {
        if (isSafeReport(report)) {++safeCount;}
    }
    return safeCount;
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
    std::vector<std::string> reports;
    std::string line;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            reports.push_back(line);
        }
    }
    inputFile.close();
    int safeReports = countSafeReports(reports);
    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}