#include "header.h"

void printHelp() {
    std::cout << "seamCarver help\n";
    std::cout << "Usage: seamCarver [filename].pgm [vertical seams to remove] [horizontal seams to remove]\n";
    std::cout << "Example: seamCarver test.pgm 50 20 - will remove 50 vertical seams and 20 horizontal seams from test.pgm and output that to test.pgm_processed.pgm\n";
}

int main(int argc, char** argv) {
    std::string filename;
    matrix initial;
    int horizontalRemove;
    int verticalRemove;
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
        if(!readMatrix(argv[1], initial))
            return 0;
    }

    int totalRemoved = 0;
    // calculate energy with current matrix
    matrix energyMatrix = calculateEnergy(initial);
    matrix cumulative = cumulativeEnergy(energyMatrix);

    do {
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulative);
        for(auto x : toRemove) {
            initial.at(x.first).erase(initial.at(x.first).begin() + x.second); // remove the colomn
        }
        totalRemoved++; // we removed one so lets tell it we did
    } while(totalRemoved < verticalRemove);

    // rotate the matrix and go again
    totalRemoved = 0; // reset for horizontal
    matrix clockWise = rotateClockWise(initial);
    matrix cumulativeRotate = rotateClockWise(cumulative); // we will need this for tracing
    do {
        //now flag them for removal by tracing through the cumulative matrix
        auto toRemove = traceForRemoval(cumulativeRotate);
        for(auto x : toRemove) {
            initial.at(x.first).erase(initial.at(x.first).begin() + x.second); // remove the colomn
        }
        totalRemoved++; // we removed one so lets tell it we did
    } while(totalRemoved < horizontalRemove);

    std::ofstream outFile;
    outFile.open(filename + "_processed.pgm", std::ios::out);
}