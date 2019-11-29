#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
typedef std::vector<std::vector<char>> matrix;

// smallest case is when there's one row, cumulative energy is sum of total row percolated through the array
matrix calculateEnergy(matrix &m) {
    std::vector<char> row;
    matrix returnedMatrix;
    int counter = 0;
    char result;
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m.at(i).size(); ++j) {
            if(i == 0 && j == 0) { // top left corner
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j)))
                );
            } else if(i == 0 && j == m.at(i).size() - 1) { // top right corner
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j)))
                );
            } else if(i == m.size() - 1 && j == 0) { // bottom left corner
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j)))
                );
            } else if(i == m.size() - 1 && j == m.at(i).size() - 1) { // bottom right corner
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j)))
                );
            } else if(j == 0) { // left edges not corners
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j)))
                );
            } else if(j == m.at(i).size() - 1) { // right edge not corners
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j)))
                );
            } else if(i == 0) { // top edge
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j)))
                );
            } else if(i == m.size() - 1) { // bottom edge
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j)))
                );
            } else { // everything else
                result = (char)(
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j + 1))) + 
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i + 1).at(j))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i - 1).at(j))) +
                    abs((int)(m.at(i).at(j)) - (int)(m.at(i).at(j - 1)))
                );
            }
            row.push_back(result);
        }
        returnedMatrix.push_back(row);
        row.clear();
        row.shrink_to_fit();
    }
    return returnedMatrix;
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

bool readMatrix(char* filename, matrix *m, int &max) {
    std::ifstream inFile;
    inFile.open(filename, std::ios::in);
    if(!inFile) {
        std::cout << "Cannot open file " << filename << ". Please try again with a different one\n";
        return false;
    }
    std::string line;
    std::vector<std::vector<int>> parsedInts;
    std::vector<int> intLine;
    int placeHolder;
    auto inserter = std::back_inserter(intLine);
    while(std::getline(inFile, line)) {
        if(line == "P2" || line.at(0) == '#') continue; // ignore the lines if they are a comment or P2
        else {
            std::istringstream iss(line);
            while(iss >> placeHolder) {
                intLine.push_back(placeHolder);
            }
            parsedInts.push_back(intLine);
            intLine.clear();
            intLine.shrink_to_fit();
        }
    }
    max = parsedInts.at(2).at(0); // set the max color value
    std::vector<char> row;
    int counter = 0;
    for(int i = 3; i < parsedInts.size(); ++i) {
        for(int j = 0; j < parsedInts.at(i).size(); ++j) {
            if(counter % parsedInts.at(1).at(0) == 0 && counter != 0) {
                m->push_back(row);
                row.clear();
                row.shrink_to_fit();
            }
            row.push_back((char)(parsedInts.at(i).at(j)));
            counter++;
        }
    }
    m->push_back(row); // catch last row
    return true;
}

std::vector<std::pair<int,int>> traceForRemoval(matrix &m) {
    
}