#include "header.h"

void printHelp() {

}

int main(int argc, char** argv) {
    matrix initial;
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
        int horizontalRemove = std::stoi(argv[1]);
        int verticalRemove = std::stoi(argv[2]);
        initial = readMatrix(argv[3]);
    }

}