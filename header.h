#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
typedef std::vector<std::vector<char>> matrix;

// smallest case is when there's one row, cumulative energy is
matrix calculateEnergy(matrix &m) {
    return m;
}

matrix cumulativeEnergy(matrix &m) {
    return m;
}

matrix rotateClockWise(matrix &m) {
    return m;
}

matrix rotateCounterClockWise(matrix &m) {
    return m;
}

bool readMatrix(char* filename, matrix &m) {
    std::ifstream inFile;
    inFile.open(filename, std::ios::in);
    if(!inFile) {
        std::cout << "Cannot open file. Please try again with a different one\n";
        return false;
    }
    return true;
}

std::vector<std::pair<int,int>> traceForRemoval(matrix &m) {
    
}