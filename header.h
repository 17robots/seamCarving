#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
typedef std::vector<std::vector<int>> matrix;

// smallest case is when there's one row, cumulative energy is sum of total row percolated through the array
matrix calculateEnergy(matrix &m)
{
    std::ofstream log;
    log.open("log2.txt", std::ios::out);
    std::vector<int> row;
    matrix returnedMatrix;
    int counter = 0;
    int result;
    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m.at(i).size(); ++j)
        {
            if (i == 0 && j == 0)
            { // top left corner
                log << "Top Left Corner\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)));
            }
            else if (i == 0 && j == m.at(i).size() - 1)
            { // top right corner
                log << "Top Right Corner\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j - 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)));
            }
            else if (i == m.size() - 1 && j == 0)
            { // bottom left corner
                log << "Bottom Left Corner\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)));
            }
            else if (i == m.size() - 1 && j == m.at(i).size() - 1)
            { // bottom right corner
                log << "Bottom Right Corner\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j - 1)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)));
            }
            else if (j == 0)
            { // left edges not corners
                log << "Left Edge\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)));
            }
            else if (j == m.at(i).size() - 1)
            { // right edge not corners
                log << "Right Edge\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j - 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)));
            }
            else if (i == 0)
            { // top edge
                log << "Top Edge\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j - 1)) +
                          abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)));
            }
            else if (i == m.size() - 1)
            { // bottom edge
                log << "Bottom Edge\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j - 1)) +
                          abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)));
            }
            else
            { // everything else
                log << "Everything Else\n";
                result = (abs(m.at(i).at(j) - m.at(i).at(j + 1)) +
                          abs(m.at(i).at(j) - m.at(i + 1).at(j)) +
                          abs(m.at(i).at(j) - m.at(i - 1).at(j)) +
                          abs(m.at(i).at(j) - m.at(i).at(j - 1)));
            }
            row.push_back(result);
        }
        returnedMatrix.push_back(row);
        row.clear();
        row.shrink_to_fit();
    }
    return returnedMatrix;
}

matrix cumulativeEnergy(matrix &m, int max)
{
    std::vector<int> row;
    matrix copy = m;
    matrix returnedMatrix;
    int counter = 0;
    int result;
    for (int i = 0; i < m.at(0).size(); ++i)
    {
        row.push_back(m.at(0).at(i));
    }
    returnedMatrix.push_back(row);
    row.clear();
    row.shrink_to_fit();
    for (int i = 1; i < m.size(); ++i)
    {
        for (int j = 0; j < m.at(i).size(); ++j)
        {
            if (row.size() % m.at(0).size() == 0 && row.size() != 0)
            {
                returnedMatrix.push_back(row);
                row.clear();
                row.shrink_to_fit();
            }
            if (j == 0)
            {
                row.push_back(
                    m.at(i).at(j) + std::min(returnedMatrix.at(i - 1).at(j), returnedMatrix.at(i - 1).at(j + 1)));
            }
            else if (j == m.at(i).size() - 1)
            {
                row.push_back(
                    m.at(i).at(j) + std::min(returnedMatrix.at(i - 1).at(j - 1), returnedMatrix.at(i - 1).at(j)));
            }
            else
            {
                row.push_back(
                    m.at(i).at(j) + std::min(std::min(returnedMatrix.at(i - 1).at(j - 1), returnedMatrix.at(i - 1).at(j)), returnedMatrix.at(i - 1).at(j + 1)));
            }
        }
    }
    returnedMatrix.push_back(row);
    return returnedMatrix;
}

void rotateClockWise(matrix &m, int max)
{
    // int currentWidth = m.at(0).size(); // grab the current witdth to use for the height
    // int currentHeight = m.size();
    // matrix copy = m; // since we could potentially be modifying stuff in the matrix
    // matrix returnedMatrix;
    // int currentSize = copy.at(copy.size() - 1).size();
    // std::vector<int> row;
    // for (int k = 0; k < currentWidth - currentSize; ++k)
    // {
    //     copy.at(copy.size() - 1).push_back(max + 1);
    // }

    // int counter = 0;
    // for (int i = 0; i < copy.at(copy.size() - 1).size(); ++i)
    // {
    //     for (int j = copy.size() - 1; j >= 0; --j)
    //     {
    //         if (counter % currentHeight == 0 && counter != 0)
    //         {
    //             returnedMatrix.push_back(row);
    //             row.clear();
    //             row.shrink_to_fit();
    //         }
    //         row.push_back(copy.at(j).at(i));
    //         counter++;
    //     }
    // }
    // returnedMatrix.push_back(row); // catch the last row

    // return returnedMatrix;

    int height = m.size(), width = m.at(0).size();
    for (int i = 0; i < width; ++i)
    {
        std::vector<int> row;
        row.resize(height);
        for (int j = 0; j < height; ++j)
            row[j] = m.at(j).at(i);
        m.push_back(row);
    }
    m.erase(m.begin(), m.begin() + height);
}

matrix rotateCounterClockWise(matrix &m, int max)
{
    matrix returnedMatrix;
    int currentHeight = m.size();
    std::vector<int> row;
    // shouldnt have to pad this one, so we can just loop through
    int counter = 0;
    for (int i = m.at(m.size() - 1).size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < m.size(); ++j)
        {
            if (counter % currentHeight == 0 && counter != 0)
            {
                returnedMatrix.push_back(row);
                row.clear();
                row.shrink_to_fit();
            }
            if (m.at(j).at(i) != max + 1)
            { // this should only matter for the last padding
                row.push_back(m.at(j).at(i));
                counter++;
            }
        }
    }
    returnedMatrix.push_back(row);
    return returnedMatrix;
}

bool readMatrix(char *filename, matrix &m, int &max)
{
    std::ifstream inFile;
    inFile.open(filename, std::ios::in);
    if (!inFile)
    {
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
        if (line.find("P2") != std::string::npos || line.find("#") != std::string::npos)
        { // handle comments and beginning line
            continue;
        }
        else
        {
            std::stringstream iss(line);
            for (int num; iss >> num;)
            {
                row.push_back(num);
            }
            readLines.push_back(row);
            row.clear();
            row.shrink_to_fit();
        }
    }
    int counter = 0;
    for (int i = 0; i < readLines.size(); ++i)
    {
        if (readLines.at(i).size() == 1 && localMax == -1)
        { // we found max
            max = readLines.at(i).at(0);
            localMax = 0;
            std::cout << "Setting max to: " << max << '\n';
        }
        else if (readLines.at(i).size() == 2 && width == -1 && height == -1)
        { // we found width and height
            width = readLines.at(i).at(0);
            height = readLines.at(i).at(1);
            std::cout << "Setting width to: " << width << '\n';
            std::cout << "Setting height to: " << height << '\n';
        }
        else
        {
            for (int j = 0; j < readLines.at(i).size(); ++j)
            { // we have normal numbers so lets loop through and add them to the matrix
                if (counter % width == 0 && counter != 0)
                {
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

std::vector<std::pair<int, int>> traceForRemoval(matrix &m)
{
    std::vector<std::pair<int, int>> toRemove;
    // start from the top to get the lowest energy source and then we can percalate up
    std::pair<int, int> lowest(m.size() - 1, 0);
    for (int i = 1; i < m.at(m.size() - 1).size(); ++i)
        if (m.at(lowest.first).at(lowest.second) > m.at(lowest.first).at(i))
            lowest.second = i;
    toRemove.push_back(lowest);
    // now we need to keep moving up the chain to find the lowest
    while (lowest.first != 0)
    {
        if (lowest.second == 0)
        {
            int val1 = m.at(lowest.first - 1).at(lowest.second), val2 = m.at(lowest.first - 1).at(lowest.second + 1);
            lowest.first--;
            if (val1 > val2)
            {
                lowest.second++;
            }
        }
        else if (lowest.second == m.at(lowest.first).size() - 1)
        {
            int val1 = m.at(lowest.first - 1).at(lowest.second - 1), val2 = m.at(lowest.first - 1).at(lowest.second);
            lowest.first--;
            if (val2 > val1)
            {
                lowest.second--;
            }
        }
        else
        {
            int val1 = m.at(lowest.first - 1).at(lowest.second - 1);
            int val2 = m.at(lowest.first - 1).at(lowest.second);
            int val3 = m.at(lowest.first - 1).at(lowest.second + 1);
            lowest.first--;
            if (val1 > val2)
            {
                if (val2 > val3)
                {
                    lowest.second++;
                }
            }
            else
            {
                if (val1 > val3)
                {
                    lowest.second++;
                }
                else
                {
                    lowest.second--;
                }
            }
        }
        // std::cout << "Pushing (" << lowest.first << ", " << lowest.second << ") to toRemove\n";
        toRemove.push_back(lowest);
    }
    return toRemove;
}

void carve(char *filename, matrix &initial, int verticalRemove, int horizontalRemove, int &max)
{
    //std::ofstream ////////logger;
    ////////logger.open("log2.txt", std::ios::out);
    std::cout << "Reading in Initial Matrix\n";
    if (!readMatrix(filename, initial, max))
        return; // there was a problem
    ////////logger << "Initial Matrix\n";
    for (auto x : initial)
    {
        for (auto y : x)
            ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
        ////////logger << '\n';
    }
    std::cout << "Attempting to removing " << verticalRemove << " vertical seams and " << horizontalRemove << " horizontal seams\n";
    if (verticalRemove > initial.at(0).size())
    {
        std::cout << "Error: The number of vertical removes (" << verticalRemove << ") is larger than the number of columns in the image (" << initial.at(0).size() << ")\n";
        return;
    }

    //Removing Vertical Seams
    for (int i = 0; i < verticalRemove; ++i)
    {
        // calculate energy with current matrix
        // std::cout << "Calculating Energy Matrix\n";
        matrix energyMatrix = calculateEnergy(initial);
        ////////logger << "Energy Matrix\n";
        for (auto x : energyMatrix)
        {
            for (auto y : x)
                ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
            ////////logger << '\n';
        }

        // calculate cumulative energy
        // std::cout << "Calculating Cumulative Energy\n";
        matrix cumulative = cumulativeEnergy(energyMatrix, max);
        ////////logger << "Cumulative Matrix\n";
        for (auto x : cumulative)
        {
            for (auto y : x)
                ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
            ////////logger << '\n';
        }
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulative);
        // std::cout << "Removing: \n";
        int totalEnergy = 0;
        for (auto x : toRemove)
        {
            // std::cout << "(" << x.first << ", " << x.second << "): " << initial.at(x.first).at(x.second) << '\n';
            totalEnergy += initial.at(x.first).at(x.second);
            auto iter = initial.at(x.first).begin();
            iter += x.second;
            initial.at(x.first).erase(iter); // remove the colomn
        }
        // std::cout << "Total Energy Removed: " << totalEnergy << '\n';
    }

    ////////logger << "Trimmed Initial Matrix\n";
    for (auto x : initial)
    {
        for (auto y : x)
            ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
        ////////logger << '\n';
    }

    // rotate the matrix and go again
    // std::cout << "Rotating initial to remove horizontal\n";
    rotateClockWise(initial, max);
    ////////logger << "Rotated Matrix\n";
    for (auto x : initial)
    {
        for (auto y : x)
            ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
        ////////logger << '\n';
    }
    for (int i = 0; i < horizontalRemove; ++i)
    {
        //now flag them for removal by tracing through the cumulative matrix
        // calculate energy with current matrix
        // std::cout << "Calculating Energy Matrix\n";
        matrix initialEnergy = calculateEnergy(initial);
        ////////logger << "Energy Matrix\n";
        for (auto x : initialEnergy)
        {
            for (auto y : x)
                ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
            ////////logger << '\n';
        }

        // calculate cumulative energy
        // std::cout << "Calculating Cumulative Energy\n";
        matrix initialAcc = cumulativeEnergy(initialEnergy, max);
        ////////logger << "Cumulative Matrix\n";
        for (auto x : initialAcc)
        {
            for (auto y : x)
                ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
            ////////logger << '\n';
        }
        auto toRemove = traceForRemoval(initialAcc);
        for (auto x : toRemove)
        {
            // std::cout << "Removing (" << x.first << ", " << x.second << ")\n";
            auto iter = initial.at(x.first).begin();
            iter += x.second;
            initial.at(x.first).erase(iter); // remove the colomn
        }
    }

    ////////logger << "Trimmed Rotated Matrix\n";
    for (auto x : initial)
    {
        for (auto y : x)
            ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
        ////////logger << '\n';
    }

    // std::cout << "Rotating counterinitial to print out\n";
    rotateClockWise(initial, max);
    ////////logger << "Final Matrix\n";
    for (auto x : initial)
    {
        // for (auto y : x)
            ////////logger << std::setw(4) << std::setfill('0') << y << ' ';
        ////////logger << '\n';
    }
}