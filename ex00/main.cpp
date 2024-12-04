#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }
    std::vector<int> leftList, rightList;
    int leftNum, rightNum;
    while (inputFile >> leftNum >> rightNum) {
        leftList.push_back(leftNum);
        rightList.push_back(rightNum);
    }
    inputFile.close();
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());
    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }
    std::cout << "Total distance: " << totalDistance << std::endl;
    return 0;
}