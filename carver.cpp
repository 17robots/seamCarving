#include "header.h"

void printHelp() {
    std::cout << "seamCarver help\n";
    std::cout << "Usage: seamCarver [filename].pgm [vertical seams to remove] [horizontal seams to remove]\n";
    std::cout << "Example: seamCarver test.pgm 50 20 - will remove 50 vertical seams and 20 horizontal seams from test.pgm and output that to test.pgm_processed.pgm\n";
}

int main(int argc, char** argv) {
    matrix initial;
    std::ofstream logger;
    logger.open("log.txt", std::ios::out);
    int horizontalRemove;
    int verticalRemove;
    int max;
    if(argc < 4) {
        if(argv[1][0] == 'h')
            printHelp();
        else
            std::cout << "Invalid Number Of Arguments. Run carver h for a list of available options\n";
        return 0;
    }
    else {
        if(argv[1][0] == 'h') {
            printHelp();
            return 0;
        }
        horizontalRemove = std::stoi(argv[3]);
        verticalRemove = std::stoi(argv[2]);
    }

    std::cout << "Reading in Initial Matrix\n";
    if(!readMatrix(argv[1], initial, max))
        return 0; // there was a problem
    logger << "Initial Matrix\n";
    for(auto x : initial) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }
    std::cout << "Attempting to removing " << verticalRemove << " vertical seams and " << horizontalRemove << " horizontal seams\n";
    if(verticalRemove > initial.at(0).size()) {
        std::cout << "Error: The number of vertical removes (" << verticalRemove << ") is larger than the number of columns in the image (" << initial.at(0).size() << ")\n"; 
        return 0;
    }

    // calculate energy with current matrix
    std::cout << "Calculating Energy Matrix\n";
    matrix energyMatrix = calculateEnergy(initial);
    logger << "Energy Matrix\n";
    for(auto x : energyMatrix) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }

    // calculate cumulative energy
    std::cout << "Calculating Cumulative Energy\n";
    matrix cumulative = cumulativeEnergy(energyMatrix, max);
    logger << "Cumulative Matrix\n";
    for(auto x : cumulative) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }
    std::cout << "Removing Vertical Seams\n";
    for(int i = 0; i < verticalRemove; ++i) {
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulative);
        std::cout << "Removing: \n";
        int totalEnergy = 0;
        for(auto x : toRemove) {
            std::cout << "(" << x.first << ", " << x.second << "): " << initial.at(x.first).at(x.second) << '\n';
            totalEnergy += initial.at(x.first).at(x.second);
            auto iter = initial.at(x.first).begin();
            iter += x.second;
            initial.at(x.first).erase(iter); // remove the colomn
            iter = cumulative.at(x.first).begin();
            iter += x.second;
            cumulative.at(x.first).erase(iter); // also do it from the cumulative one
        }
        std::cout << "Total Energy Removed: " << totalEnergy << '\n';
    } 

    logger << "Trimmed Initial Matrix\n";
    for(auto x : initial) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }

    // rotate the matrix and go again
    std::cout << "Rotating clockwise to remove horizontal\n";
    matrix clockWise = rotateClockWise(initial, max);
    logger << "Rotated Matrix\n";
    for(auto x : clockWise) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }

    matrix cumulativeRotate = rotateClockWise(cumulative, max); // we will need this for tracing
    logger << "Rotated Cumulative Matrix\n";
    for(auto x : cumulativeRotate) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }
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

    logger << "Trimmed Rotated Matrix\n";
    for(auto x : clockWise) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }

    std::cout << "Rotating counterclockwise to print out\n";
    matrix final = rotateCounterClockWise(clockWise, max);
    logger << "Final Matrix\n";
    for(auto x : final) {
        for(auto y : x)
            logger << std::setw(4) << std::setfill('0') << y << ' ';
        logger << '\n';
    }

    // matrix final = carve(argv[1], initial, verticalRemove, horizontalRemove, max);
    std::ofstream outFile;
    outFile.open(std::string(argv[1]).substr(0,std::string(argv[1]).length() - 4) + "_processed.pgm", std::ios::out);

    // lastly we need to write out to a file
    outFile << "P2\n";
    outFile << "# Generated By SeamCarver\n";
    outFile << final.at(0).size() << ' ' << final.size() << '\n'; // print out width and height
    outFile << max << '\n'; // print out the max value
    for(auto x : final) {
        for(auto y : x)
            outFile << y << ' ';
        outFile << '\n';
    }
    outFile.close();
}