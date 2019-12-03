#include "header.h";

bool test1() {
    std::cout << "Running bug_processed_20_15 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./bug_processed_20_15.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/bug.pgm", initial, 20, 15);
    return toTest == correctAnswer;
}

bool test2() {
    std::cout << "Running CAS_processed_100_50 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./CAS_processed_100_50.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/CAS.pgm", initial, 100, 50);
    return toTest == correctAnswer;
}

bool test3() {
    std::cout << "Running joconde_processed_0_150 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./joconde_processed_0_150.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/joconde.pgm", initial, 0, 150);
    return toTest == correctAnswer;
}

bool test4() {
    std::cout << "Running test_processed_0_2 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./test_processed_0_2.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/test.pgm", initial, 0, 2);
    return toTest == correctAnswer;
}

bool test5() {
    std::cout << "Running test_processed_1_0 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./test_processed_1_0.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/test.pgm", initial, 1, 0);
    return toTest == correctAnswer;
}

bool test6() {
    std::cout << "Running test_processed_1_1 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./test_processed_1_1.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/test.pgm", initial, 1, 1);
    return toTest == correctAnswer;
}

bool test7() {
    std::cout << "Running test2_processed_0_1 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./test2_processed_0_1.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/test2.pgm", initial, 0, 1);
    return toTest == correctAnswer;
}

bool test8() {
    std::cout << "Running twoBalls_processed_0_116 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./twoBalls_processed_0_116.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 0, 116);
    return toTest == correctAnswer;
}

bool test9() {
    std::cout << "Running twoBalls_processed_68_0 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./twoBalls_processed_68_0.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 68, 0);
    return toTest == correctAnswer;
}

bool test10() {
    std::cout << "Running twoBalls_processed_211_68 Test\n";
    int max;
    matrix correctAnswer;
    if(readMatrix("./twoBalls_processed_211_68.pgm", correctAnswer, max)) {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 211, 68);
    return toTest == correctAnswer;
}

int main() {
    int totalPass = 0;
    int totalFail = 0;
    std::cout << "Running Tests\n";
    bool result = test1();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test2();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test3();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test3();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test4();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test5();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test6();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test7();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test8();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test9();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    result = result & test10();
    if(result) {
        std::cout << "Test Passed\n";
        totalPass++;
    } else {
        std::cout << "Test Failed\n";
        totalFail++;    
    }

    std::cout << "Tests Passed: " << totalPass << '\n';
    std::cout << "Total Fail: \n" << totalFail << '\n';

    return 0;
}