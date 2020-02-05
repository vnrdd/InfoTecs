#include "Primes.h"

int EMPTY_CONSTRUCTOR_TEST() {
    Primes p;
    return 0 == p.size();
}

int BORDER_CONSTRUCTOR_TEST() {
    int successes = 0;
    Primes p1(10);
    successes += (p1.size() == 4);
    Primes p2(20);
    successes += (p2.size() == 8);
    Primes p3(30);
    successes += (p3.size() == 10);
    Primes p4(40);
    successes += (p4.size() == 12);
    Primes p5(50);
    successes += (p5.size() == 15);
    return successes;
}

int SIZE_TEST() {
    int successes = 0;
    Primes p;
    p.insert(2);
    successes += (p.size() == 1);

    p.insert(4);
    successes += (p.size() == 1);

    p.insert(5);
    p.insert(3);
    successes += (p.size() == 3);

    p.erase(5);
    successes += (p.size() == 2);

    p.erase(0);
    successes += (p.size() == 2);
    return successes;
}

int INSERT_TEST() {
    int successes = 0;
    Primes p;
    p.insert(2);
    successes += (p[0] == 2);
    p.insert(3);
    successes += (p[1] == 3);
    p.insert(7);
    successes += (p[2] == 7);
    p.insert(11);
    successes += (p[3] == 11);
    p.insert(13);
    successes += (p[4] == 13);
    return successes;
}

int ERASE_TEST() {
    int successes = 0;
    Primes p(20);
    p.erase(2);
    successes += (p.size() == 7);
    p.erase(5);
    successes += (p.size() == 6);
    p.erase(4);
    successes += (p.size() == 6);
    p.erase(7);
    successes += (p.size() == 5);
    p.erase(10);
    successes += (p.size() == 5);
    return successes;
}

int FIND_TEST() {
    int successes = 0;
    Primes p(100);
    Primes test(10);
    p.find(10, 0);
    successes += (p == test);

    new (&test) Primes(100);
    p.find();
    successes += (p == test);

    new (&test) Primes(40);
    p.find(12, 1);
    successes += (p == test);

    new (&test) Primes;
    p.find(0, 1);
    successes += (p == test);

    p.find(0, 0);
    successes += (p == test);
    return successes;
}

int BRACKET_OPERATOR_TEST() {
    int successes = 0;
    Primes p(30);
    try {
        p[-1];
    } catch (std::exception &ex) {
        successes += 1;
    }
    successes += (p[3] == 7);
    successes += (p[0] == 2);
    successes += (p[2] == 5);
    successes += (p[7] == 19);
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
    std::cout << "\nResult of all tests: " << successes << "/31 (" << (int)precentage << "%)\n\n";
}

int main(int argc, char **argv) {
    RUN_ALL_TESTS();
    return 0;
}