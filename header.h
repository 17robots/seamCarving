#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>
typedef std::vector<std::vector<int>> matrix;

// smallest case is when there's one row, cumulative energy is sum of total row percolated through the array
matrix calculateEnergy(matrix &m) {
    std::ofstream log;
    log.open("log2.txt", std::ios::out);
    std::vector<int> row;
    matrix returnedMatrix;
    int counter = 0;
    int result;
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m.at(i).size(); ++j) {
            if(i == 0 && j == 0) { // top left corner
                log << "Top Left Corner\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) + 
                    abs(m.at(i).at(j) - m.at(i + 1).at(j))
                );
            } else if(i == 0 && j == m.at(i).size() - 1) { // top right corner
                log << "Top Right Corner\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j - 1)) + 
                    abs(m.at(i).at(j) - m.at(i + 1).at(j))
                );
            } else if(i == m.size() - 1 && j == 0) { // bottom left corner
                log << "Bottom Left Corner\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) + 
                    abs(m.at(i).at(j) - m.at(i - 1).at(j))
                );
            } else if(i == m.size() - 1 && j == m.at(i).size() - 1) { // bottom right corner
                log << "Bottom Right Corner\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j - 1)) + 
                    abs(m.at(i).at(j) - m.at(i - 1).at(j))
                );
            } else if(j == 0) { // left edges not corners
                log << "Left Edge\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) + 
                    abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                    abs(m.at(i).at(j) - m.at(i - 1).at(j))
                );
            } else if(j == m.at(i).size() - 1) { // right edge not corners
                log << "Right Edge\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j - 1)) + 
                    abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                    abs(m.at(i).at(j) - m.at(i - 1).at(j))
                );
            } else if(i == 0) { // top edge
                log << "Top Edge\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j - 1)) + 
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                    abs(m.at(i).at(j) - m.at(i + 1).at(j))
                );
            } else if(i == m.size() - 1) { // bottom edge
                log << "Bottom Edge\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j - 1)) + 
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                    abs(m.at(i).at(j) - m.at(i - 1).at(j))
                );
            } else { // everything else
                log << "Everything Else\n";
                result = (
                    abs(m.at(i).at(j) - m.at(i).at(j + 1)) + 
                    abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                    abs(m.at(i).at(j) - m.at(i - 1).at(j)) +
                    abs(m.at(i).at(j) - m.at(i).at(j - 1))
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

matrix cumulativeEnergy(matrix &m, int max) {
    std::vector<int> row;
    matrix copy = m;
    matrix returnedMatrix;
    int counter = 0;
    int result;
    for(int i = 0; i < copy.size(); ++i) {
        for(int j = 0; j < copy.at(i).size(); ++j) {
            if(i == 0 && j == 0) { // top left corner
                result = (copy.at(i).at(j) + std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j))) < max ? (
                    copy.at(i).at(j) + std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j)))
                ) : (max));
            } else if(i == 0 && j == copy.at(i).size() - 1) { // top right corner
                result = (copy.at(i).at(j) + std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i + 1).at(j))) < max ? (
                    copy.at(i).at(j) + std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i + 1).at(j)))
                ) : (max));
            } else if(i == copy.size() - 1 && j == 0) { // bottom left corner
                result = (copy.at(i).at(j) + std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i - 1).at(j))) < max ? (
                    copy.at(i).at(j) + std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i - 1).at(j)))
                ) : (max));
            } else if(i == copy.size() - 1 && j == copy.at(i).size() - 1) { // bottom right corner
                result = (copy.at(i).at(j) + std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i - 1).at(j))) < max ? (
                    copy.at(i).at(j) + std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i - 1).at(j)))
                ) : (max));
            } else if(j == 0) { // left edges not corners
                result = (copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j))), (int)(copy.at(i - 1).at(j))) < max ? ( 
                    copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j))), (int)(copy.at(i - 1).at(j)))
                ) : (max));
            } else if(j == copy.at(i).size() - 1) { // right edge not corners
                result = (copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i + 1).at(j))), (int)(copy.at(i - 1).at(j))) < max ? (copy.at(i).at(j) + 
                    copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i + 1).at(j))), (int)(copy.at(i - 1).at(j)))
                ) : (max));
            } else if(i == 0) { // top edge
                result = (copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i).at(j + 1))), (int)(copy.at(i + 1).at(j))) < max ? ( 
                    copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i).at(j + 1))), (int)(copy.at(i + 1).at(j)))
                ) : (max));
            } else if(i == copy.size() - 1) { // bottom edge
                result = (copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i).at(j + 1))), (int)(copy.at(i - 1).at(j))) < max ? (
                    copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j - 1)), (int)(copy.at(i).at(j + 1))), (int)(copy.at(i - 1).at(j)))
                ) : (max));
            } else { // everything else
                result = (copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j))), std::min((int)(copy.at(i - 1).at(j)), (int)(copy.at(i).at(j - 1)))) < max ? (
                    copy.at(i).at(j) + std::min(std::min((int)(copy.at(i).at(j + 1)), (int)(copy.at(i + 1).at(j))), std::min((int)(copy.at(i - 1).at(j)), (int)(copy.at(i).at(j - 1))))
                ) : (max));
            }
            row.push_back(result);
            copy.at(i).at(j) = result;
        }
        returnedMatrix.push_back(row);
        row.clear();
        row.shrink_to_fit();
    }
    return returnedMatrix;
}

matrix rotateClockWise(matrix &m, int max) {
    int currentWidth = m.at(0).size(); // grab the current witdth to use for the height
    int currentHeight = m.size();
    matrix copy = m; // since we could potentially be modifying stuff in the matrix
    matrix returnedMatrix;
    int currentSize = copy.at(copy.size() - 1).size();
    std::vector<int> row;
    for(int k = 0; k < currentWidth - currentSize; ++k) {
        copy.at(copy.size() - 1).push_back(max + 1);
    }

    int counter = 0;
    for(int i = 0; i < copy.at(copy.size() - 1).size(); ++i) {
        for(int j = copy.size() - 1; j >= 0; --j) {
            if(counter % currentHeight == 0 && counter != 0) {
                returnedMatrix.push_back(row);
                row.clear();
                row.shrink_to_fit();
            }
            row.push_back(copy.at(j).at(i));
            counter++;
        }
    }
    returnedMatrix.push_back(row); // catch the last row

    return returnedMatrix;
}

matrix rotateCounterClockWise(matrix &m, int max) {
    matrix returnedMatrix;
    int currentHeight = m.size();
    std::vector<int> row;
    // shouldnt have to pad this one, so we can just loop through
    int counter = 0;
    for(int i = m.at(m.size() - 1).size() - 1; i >= 0; --i) {
        for(int j = 0; j < m.size(); ++j) {
            if(counter % currentHeight == 0 && counter != 0) {
                returnedMatrix.push_back(row);
                row.clear();
                row.shrink_to_fit();
            }
            if(m.at(j).at(i) != max + 1) { // this should only matter for the last padding
                row.push_back(m.at(j).at(i));
                counter++;
            }
        }
    }
    returnedMatrix.push_back(row);
    return returnedMatrix;
}

bool readMatrix(char* filename, matrix &m, int &max) {
    std::ifstream inFile;
    inFile.open(filename, std::ios::in);
    if(!inFile) {
        std::cout << "Could not open file " << filename << ". Please try again with another one\n";
        return false;
    }
    // valid file so lets read
    std::string line;
    matrix readLines;
    std::vector<int> row;
    int localMax = -1; // used to flag for being set
    int width = -1, height = -1;
    while (std::getline(inFile, line))
    {
        if(line.find("P2") != std::string::npos || line.find("#") != std::string::npos) { // handle comments and beginning line
            continue;
        } else {
            std::stringstream iss(line);
            for(int num; iss >> num;) {
                row.push_back(num);
            }
            readLines.push_back(row);
            row.clear();
            row.shrink_to_fit();
        }
    }
    int counter = 0;
    for(int i = 0; i < readLines.size(); ++i) {
        if(readLines.at(i).size() == 1 && localMax == -1) { // we found max
            max = readLines.at(i).at(0);
            localMax = 0;
            std::cout << "Setting max to: " << max << '\n';
        } else if(readLines.at(i).size() == 2 && width == -1 && height == -1) { // we found width and height
            width = readLines.at(i).at(0);
            height = readLines.at(i).at(1);
            std::cout << "Setting width to: " << width << '\n';
            std::cout << "Setting height to: " << height << '\n';
        } else {
            for(int j = 0; j < readLines.at(i).size(); ++j) { // we have normal numbers so lets loop through and add them to the matrix
                if(counter % width == 0 && counter != 0) {
                    m.push_back(row);
                    row.clear();
                    row.shrink_to_fit();
                }
                row.push_back(readLines.at(i).at(j));
                counter++;
            }
        }
    }
    m.push_back(row);

    inFile.close();
    
    return true;
}

std::vector<std::pair<int,int>> traceForRemoval(matrix &m) {
    std::vector<std::pair<int, int>> toRemove;
    // start from the top to get the lowest energy source and then we can percalate down
    std::pair<int, int> lowest(0,0);
    for(int i = 0; i < m.at(0).size(); ++i)
        if(m.at(lowest.first).at(lowest.second) > m.at(0).at(i))
            lowest = std::pair<int,int>(0, i);
    toRemove.push_back(lowest);
    // now we need to keep moving down the chain to find the lowest
    while(lowest.first != m.size() - 1) {
        if(lowest.second == m.at(0).size() - 1) {
            if(m.at(lowest.first + 1).at(lowest.second) > m.at(lowest.first + 1).at(lowest.second - 1)) {
                lowest.second -= 1;
            }
        } else if(lowest.second == 0) {
            if(m.at(lowest.first + 1).at(lowest.second) > m.at(lowest.first + 1).at(lowest.second + 1)) {
                lowest.second += 1;
            }
        } else {
            if(m.at(lowest.first + 1).at(lowest.second) > m.at(lowest.first + 1).at(lowest.second - 1)) {
                if(m.at(lowest.first + 1).at(lowest.second - 1) > m.at(lowest.first + 1).at(lowest.second + 1)) {
                    lowest.second += 1;
                } else {
                    lowest.second -= 1;
                }
            } else {
                if(m.at(lowest.first + 1).at(lowest.second) > m.at(lowest.first + 1).at(lowest.second + 1)) {
                    lowest.second += 1;
                }
            }
        }
        if(lowest.first + 1 < m.size()) {
            lowest.first++;
            toRemove.push_back(lowest);
        } else {
            break;
        }
    }
    return toRemove;
}

matrix carve(char* filename, matrix &initial, int verticalRemove, int horizontalRemove) {
    int max;
    std::cout << "Reading in Initial Matrix\n";
    if(!readMatrix(filename, initial, max))
        return {{-1}}; // there was a problem
    
    std::cout << "Attempting to removing " << verticalRemove << " vertical seams and " << horizontalRemove << " horizontal seams\n";
    if(verticalRemove > initial.at(0).size()) {
        std::cout << "Error: The number of vertical removes (" << verticalRemove << ") is larger than the number of columns in the image (" << initial.at(0).size() << ")\n"; 
        return {{-1}};
    }

    // calculate energy with current matrix
    std::cout << "Calculating Energy Matrix\n";
    matrix energyMatrix = calculateEnergy(initial);

    // calculate cumulative energy
    std::cout << "Calculating Cumulative Energy\n";
    matrix cumulative = cumulativeEnergy(energyMatrix, max);

    std::cout << "Removing Vertical Seams\n";
    for(int i = 0; i < verticalRemove; ++i) {
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulative);

        for(auto x : toRemove) {
            auto iter = initial.at(x.first).begin();
            iter += x.second;
            initial.at(x.first).erase(iter); // remove the colomn
            iter = cumulative.at(x.first).begin();
            iter += x.second;
            cumulative.at(x.first).erase(iter); // also do it from the cumulative one
        }
    } 

    // rotate the matrix and go again
    std::cout << "Rotating clockwise to remove horizontal\n";
    matrix clockWise = rotateClockWise(initial, max);
    matrix cumulativeRotate = rotateClockWise(cumulative, max); // we will need this for tracing

    for(int i = 0; i < horizontalRemove; ++i) {
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulativeRotate);
        for(auto x : toRemove) {
            auto iter = clockWise.at(x.first).begin();
            iter += x.second;
            clockWise.at(x.first).erase(iter); // remove the colomn
            iter = cumulativeRotate.at(x.first).begin();
            iter += x.second;
            cumulativeRotate.at(x.first).erase(iter); // also do it from the cumulative one
        }
    }

    std::cout << "Rotating counterclockwise to print out\n";
    matrix final = rotateCounterClockWise(clockWise, max);
    return final;
}