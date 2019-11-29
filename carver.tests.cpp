#include "header.h"

// test cases defined here
bool case1A() {
    matrix testCase = {
        {(char)(65), (char)(65), (char)(66), (char)(66)},
        {(char)(66), (char)(66), (char)(66), (char)(67)}
    };
    matrix correctAnswer = {
        {(char)(1), (char)(2), (char)(1), (char)(1)},
        {(char)(1), (char)(1), (char)(1), (char)(2)}
    };
    matrix toTest = calculateEnergy(testCase);
    // matrix toTest = {};
    if(toTest != correctAnswer) {
        std::cout << "Calculated Value Does Not Match Correct Value\n";
        std::cout << "Correct Value:\n";
        for(auto x : correctAnswer) {
            for(auto y : x)
                std::cout << (int)(y) << ' ';
            std::cout << "\n";
        }

        std::cout << "Calculated Answed:\n";
        for(auto x : toTest) {
            for(auto y : x)
                std::cout << (int)(y) << ' ';
            std::cout << "\n";
        }
    }
    return correctAnswer == toTest;
}

bool case2A() {
    matrix testCase = {};
    matrix correctAnswer = {};
    return correctAnswer == cumulativeEnergy(testCase);
}

bool case3A() {
    matrix testCase = {};
    matrix correctAnswer = {};
    return correctAnswer == rotateClockWise(testCase);
}

bool case4A() {
    matrix testCase = {};
    matrix correctAnswer = {};
    return correctAnswer == rotateCounterClockWise(testCase);
}

bool case5A() {
    std::cout << "Test 5a\n";
    matrix testCase;
    matrix correctAnswer = {
        {(char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65)},
        {(char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65)},
        {(char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(65), (char)(66), (char)(66), (char)(66)},
        {(char)(67), (char)(65), (char)(65)}};
    int correctMax = 255;
    char* filename = "TestCase.pgm";
    matrix toTest;
    int max;
    if(readMatrix(filename, &toTest, max)) {
        if(correctAnswer != toTest)
            std::cout << "The returned value does not match the correct value\n";
        if(max != correctMax)
            std::cout << "The returned max value does not match the correct max value\n";
        return correctAnswer == toTest && max == correctMax;
    }
    return false;
}

// calculateEnergy Tests
bool test1() {
    return case1A();
}

// cumulativeEnergy Tests
bool test2() {
    return case2A();
}

// rotateClockWise Tests
bool test3() {
    return case3A();
}

// rotateCounterClockWise Tests
bool test4() {
    return case4A();
}

// readMatrix Tests
bool test5() {
    return case5A();
}

int main() {
    int totalPass, totalFail;
    bool result;
    std::cout << "Running CalculateEnergy Tests...";
    result = test1();
    std::cout << (result ? "Tests Passed\n" : "Tests Failed\n");
    totalPass += result ? 1 : 0;
    totalFail += result ? 0 : 1;

    std::cout << "Running CumulativeEnergy Tests...";
    result = test2();
    std::cout << (result ? "Tests Passed\n" : "Tests Failed\n");
    totalPass += result ? 1 : 0;
    totalFail += result ? 0 : 1;

    std::cout << "Running RotateClockWise Tests...";
    result = test3();
    std::cout << (result ? "Tests Passed\n" : "Tests Failed\n");
    totalPass += result ? 1 : 0;
    totalFail += result ? 0 : 1;

    std::cout << "Running RotateCounterClockWise Tests...";
    result = test4();
    std::cout << (result ? "Tests Passed\n" : "Tests Failed\n");
    totalPass += result ? 1 : 0;
    totalFail += result ? 0 : 1;
    
    std::cout << "Running ReadMatrix Tests...";
    result = test5();
    std::cout << (result ? "Tests Passed\n" : "Tests Failed\n");
    totalPass += result ? 1 : 0;
    totalFail += result ? 0 : 1;

    std::cout << "Test Sections Passed: " << totalPass << '\n';
    std::cout << "Test Sections Failed: " << totalFail << '\n';
}