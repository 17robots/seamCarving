#include "header.h"

// test cases defined here
bool case1A() {
    matrix testCase = {};
    matrix correctAnswer = {};
    return correctAnswer == calculateEnergy(testCase);
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
    matrix testCase = {};
    matrix correctAnswer = {};
    char filename[13] = "TestCase.pgm";
    return correctAnswer == readMatrix(filename);
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