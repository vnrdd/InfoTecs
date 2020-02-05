#include "Primes.h"

template <typename T>
int EQUAL_AND_PRINT(T frst, int second) {
    if (frst == second) {
        std::cout << "PASSED";
        return 1;
    }
    std::cout << "FAILED";
    return 0;
}

template <typename T>
int EQUAL_AND_PRINT(T frst, T second) {
    if (frst == second) {
        std::cout << "PASSED";
        return 1;
    }
    std::cout << "FAILED";
    return 0;
}

int EMPTY_CONSTRUCTOR_TEST() {
    std::cout << "\n~~~ EMPTY CONSTRUCTOR TEST ~~~\n";
    Primes p;
    std::cout << "Test 1/1 - ";
    return EQUAL_AND_PRINT(p.size(), 0);
}

int BORDER_CONSTRUCTOR_TEST() {
    std::cout << "\n\n~~~ BORDED CONSTRUCTOR TEST ~~~\n";
    int successes = 0;
    Primes p1(10);
    std::cout << "Test 1/5 - ";
    successes += EQUAL_AND_PRINT(p1.size(), 4);

    Primes p2(20);
    std::cout << "\nTest 2/5 - ";
    successes += EQUAL_AND_PRINT(p2.size(), 8);

    Primes p3(30);
    std::cout << "\nTest 3/5 - ";
    successes += EQUAL_AND_PRINT(p3.size(), 10);

    Primes p4(40);
    std::cout << "\nTest 4/5 - ";
    successes += EQUAL_AND_PRINT(p4.size(), 12);
    Primes p5(50);
    std::cout << "\nTest 5/5 - ";
    successes += EQUAL_AND_PRINT(p5.size(), 15);
    return successes;
}

int SIZE_TEST() {
    std::cout << "\n\n~~~ SIZE TEST ~~~\n";
    int successes = 0;
    Primes p;

    std::cout << "Test 1/5 - ";
    p.insert(2);
    successes += EQUAL_AND_PRINT(p.size(), 1);

    std::cout << "\nTest 2/5 - ";
    p.insert(4);
    successes += EQUAL_AND_PRINT(p.size(), 1);

    std::cout << "\nTest 3/5 - ";
    p.insert(5);
    p.insert(3);
    successes += EQUAL_AND_PRINT(p.size(), 3);

    std::cout << "\nTest 4/5 - ";
    p.erase(5);
    successes += EQUAL_AND_PRINT(p.size(), 2);

    std::cout << "\nTest 5/5 - ";
    p.erase(0);
    successes += EQUAL_AND_PRINT(p.size(), 2);

    return successes;
}

int INSERT_TEST() {
    std::cout << "\n\n~~~ INSERT TEST ~~~\n";
    int successes = 0;
    Primes p;

    std::cout << "Test 1/5 - ";
    p.insert(2);
    successes += EQUAL_AND_PRINT(p[0], 2);

    std::cout << "\nTest 2/5 - ";
    p.insert(3);
    successes += EQUAL_AND_PRINT(p[1], 3);

    std::cout << "\nTest 3/5 - ";
    p.insert(7);
    successes += EQUAL_AND_PRINT(p[2], 7);

    std::cout << "\nTest 4/5 - ";
    p.insert(11);
    successes += EQUAL_AND_PRINT(p[3], 11);

    std::cout << "\nTest 5/5 - ";
    p.insert(13);
    successes += EQUAL_AND_PRINT(p[4], 13);

    return successes;
}

int ERASE_TEST() {
    std::cout << "\n\n~~~ ERASE TEST ~~~\n";
    int successes = 0;
    Primes p(20);

    std::cout << "Test 1/5 - ";
    p.erase(2);
    successes += EQUAL_AND_PRINT(p.size(), 7);

    std::cout << "\nTest 2/5 - ";
    p.erase(5);
    successes += EQUAL_AND_PRINT(p.size(), 6);

    std::cout << "\nTest 3/5 - ";
    p.erase(4);
    successes += EQUAL_AND_PRINT(p.size(), 6);

    std::cout << "\nTest 4/5 - ";
    p.erase(7);
    successes += EQUAL_AND_PRINT(p.size(), 5);

    std::cout << "\nTest 5/5 - ";
    p.erase(10);
    successes += EQUAL_AND_PRINT(p.size(), 5);

    return successes;
}

int FIND_TEST() {
    std::cout << "\n\n~~~ FIND TEST ~~~\n";
    int successes = 0;
    Primes p(100);
    Primes test(10);

    std::cout << "Test 1/5 - ";
    p.find(10, 0);
    successes += EQUAL_AND_PRINT(p, test);

    std::cout << "\nTest 2/5 - ";
    new (&test) Primes(100);
    p.find();
    successes += EQUAL_AND_PRINT(p, test);

    std::cout << "\nTest 3/5 - ";
    new (&test) Primes(40);
    p.find(12, 1);
    successes += EQUAL_AND_PRINT(p, test);

    std::cout << "\nTest 4/5 - ";
    new (&test) Primes;
    p.find(0, 1);
    successes += EQUAL_AND_PRINT(p, test);

    std::cout << "\nTest 5/5 - ";
    p.find(0, 0);
    successes += EQUAL_AND_PRINT(p, test);
    return successes;
}

int BRACKET_OPERATOR_TEST() {
    std::cout << "\n\n~~~ BRACKET OPERATOR TEST ~~~\n";
    int successes = 0;
    Primes p(30);

    std::cout << "Test 1/5 - ";
    try {
        p[-1];
    } catch (std::exception &ex) {
        std::cout << "PASSED";
        successes += 1;
    }

    std::cout << "\nTest 5/5 - ";
    successes += EQUAL_AND_PRINT(p[3], 7);

    std::cout << "\nTest 5/5 - ";
    successes += EQUAL_AND_PRINT(p[0], 2);

    std::cout << "\nTest 5/5 - ";
    successes += EQUAL_AND_PRINT(p[2], 5);

    std::cout << "\nTest 5/5 - ";
    successes += EQUAL_AND_PRINT(p[7], 19);
    return successes;
}

void RUN_ALL_TESTS() {
    double successes = 0;
    successes += EMPTY_CONSTRUCTOR_TEST();
    successes += BORDER_CONSTRUCTOR_TEST();
    successes += SIZE_TEST();
    successes += INSERT_TEST();
    successes += ERASE_TEST();
    successes += FIND_TEST();
    successes += BRACKET_OPERATOR_TEST();
    double precentage = successes / 31 * 100;

    std::cout << "\n\n/////////////////////////////////////////\n";
    std::cout << "Result of all tests: " << successes << "/31 (" << (int)precentage << "%)\n";
    std::cout << "/////////////////////////////////////////\n\n";
}

int main(int argc, char **argv) {
    RUN_ALL_TESTS();
    return 0;
}