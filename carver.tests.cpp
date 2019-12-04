#include "header.h"

std::ofstream logger;

bool test1()
{
    logger << "Running bug_processed_20_15 Test\n";
    int max;
    matrix correctAnswer;

    if (readMatrix("projectTests/bug_processed_20_15.pgm", correctAnswer, max))
    {
        std::cout << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/bug.pgm", initial, 20, 15, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/bug.pgm", initial, 20, 15, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test2()
{
    logger << "Running CAS_processed_100_50 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/CAS_processed_100_50.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/CAS.pgm", initial, 100, 50, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/CAS.pgm", initial, 100, 50, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test3()
{
    logger << "Running joconde_processed_0_150 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/joconde_processed_0_150.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/joconde.pgm", initial, 0, 150, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/joconde.pgm", initial, 0, 150, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test4()
{
    logger << "Running test_processed_0_2 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/test_processed_0_2.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/test.pgm", initial, 0, 2, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/test.pgm", initial, 0, 2, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test5()
{
    logger << "Running test_processed_1_0 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/test_processed_1_0.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/test.pgm", initial, 1, 0, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/test.pgm", initial, 1, 0, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test6()
{
    logger << "Running test_processed_1_1 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/test_processed_1_1.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/test.pgm", initial, 1, 1, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/test.pgm", initial, 1, 1, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test7()
{
    logger << "Running test2_processed_0_1 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/test2_processed_0_1.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/test2.pgm", initial, 0, 1, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/test2.pgm", initial, 0, 1, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test8()
{
    logger << "Correct Answer\n";
    logger << "Running twoBalls_processed_0_116 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/twoBalls_processed_0_116.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/twoBalls.pgm", initial, 0, 116, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 0, 116, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test9()
{
    logger << "Running twoBalls_processed_68_0 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/twoBalls_processed_68_0.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/twoBalls.pgm", initial, 68, 0, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 68, 0, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

bool test10()
{
    logger << "Running twoBalls_processed_211_68 Test\n";
    int max;
    matrix correctAnswer;
    if (readMatrix("projectTests/twoBalls_processed_211_68.pgm", correctAnswer, max))
    {
        logger << "Successfully read in correct matrix\n";
    }
    matrix initial;
<<<<<<< HEAD
    carve("projectTests/twoBalls.pgm", initial, 211, 68, max);
    bool result = initial == correctAnswer;
=======
    matrix toTest = carve("projectTests/twoBalls.pgm", initial, 211, 68, max);
    bool result = toTest == correctAnswer;
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
    if (!result)
    {
        int totalDiff = 0;
        logger << "Differences: \n";
<<<<<<< HEAD
        for(int i = 0; i < initial.size(); ++i) {
            for(int j = 0; j < initial.at(i).size(); ++j) {
                if(initial.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << initial.at(i).at(j) << ")\n";
=======
        for(int i = 0; i < toTest.size(); ++i) {
            for(int j = 0; j < toTest.at(i).size(); ++j) {
                if(toTest.at(i).at(j) != correctAnswer.at(i).at(j)) {
                    logger << "Difference at " << i << ", j: " << j << " (Correct: " << correctAnswer.at(i).at(j) << ", Calculated: " << toTest.at(i).at(j) << ")\n";
>>>>>>> 6af4c4348095384c2b73e420284769bac69c26e9
                    totalDiff++;
                }
            }
        }
        std::cout << "Total Diff: " << totalDiff << '\n';
    }
    return result;
}

int main()
{
    logger.open("log.txt", std::ios::out);
    int totalPass = 0;
    int totalFail = 0;
    std::cout << "Running Tests\n";
    bool result = test1();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test2();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test3();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test3();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test4();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test5();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test6();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test7();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test8();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test9();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }

    result = result & test10();
    if (result)
    {
        std::cout << "Test Passed\n";
        totalPass++;
    }
    else
    {
        std::cout << "Test Failed\n";
        totalFail++;
    }
    logger.close();
    std::cout << "Tests Passed: " << totalPass << '\n';
    std::cout << "Total Fail: "
              << totalFail << '\n';

    return 0;
}