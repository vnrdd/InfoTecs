#include "Primes.h"

void menu(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "\n*** PLEASE INPUT 1 FILE VIA COMMAND LINE ***\n";
        std::cout << "/ we need file to output data if you want during the programm /\n\n";
        return;
    }

    else if (!checkFile(argv[1])) {
        std::cout << "\n*** PLEASE INPUT CORRECT FILE NAME ***\n";
        std::cout << "/ we need file to output data if you want during the programm /\n\n";
        return;
    }

    std::cout << "\n /// HI! Lets create our Primes Container! ///";
    int answerFlag = 0;
    while (answerFlag != 1 && answerFlag != 2) {
        std::cout << "\n\nDo you want to create empty container (1) or up border container (2)?\n ~~~ ANSWER: ";
        std::cin >> answerFlag;
        if (answerFlag != 1 && answerFlag != 2) std::cout << "*** TRY AGAIN ***";
    }

    Primes p;

    if (answerFlag == 2) {
        int max = 0;
        std::cout << std::endl;
        while (max <= 1) {
            std::cout << "Please input the up border (>1): ";
            std::cin >> max;
        }
        new (&p) Primes(max);
    }

    std::cout << "\n/~/ Container was successfully created /~/\n\n";

    std::cout << "\n/// GREAT! Lets work with our container! ///\n";
    answerFlag = 7;
    while (answerFlag != 0) {
        std::cout << "\nWhat do you want to do:\n";
        std::cout << "0. Exit\n1. Insert value\n2. Erase value\n3. Find a sequence\n";
        std::cout << "4. Print the whole container\n5. Print Super Primes\n6. Print Sophie Primes\n";
        while (answerFlag < 0 || answerFlag > 6) {
            std::cout << "~~~ ANSWER: ";
            std::cin >> answerFlag;
        }
        switch (answerFlag) {
            case 0:
                std::cout << "\nSee ya! -_0\n\n";
                break;

            case 1: {
                uint64_t value = 0;
                std::cout << "\n~~~ INPUT THE VALUE TO INSERT(i wont be added if its not prime): ";
                std::cin >> value;
                if ((p.insert(value)).second == 1)
                    std::cout << "...Complete\n";
                else
                    std::cout << "*** You cant add this number ***\n";
                std::cout << "\nLETS CONTINUE!";
                answerFlag = 7;
                break;
            }

            case 2: {
                uint64_t value = 0;
                std::cout << "\n~~~ INPUT THE VALUE TO ERASE: ";
                std::cin >> value;
                if (p.erase(value) == 0)
                    std::cout << "*** There is such a number ***\n";
                else
                    std::cout << "...Complete\n";
                answerFlag = 7;
                break;
            }

            case 3: {
                int extraFlag = 0;
                while (extraFlag != 1 && extraFlag != 2 && extraFlag != 3) {
                    std::cout << "\n  3.1. Sequence with up border (1)\n  3.2. Sequence with given count (2)\n  3.3. Default sequence under 100 (3)\n";
                    std::cout << "  ~~~ ANSWER: ";
                    std::cin >> extraFlag;
                }

                int parameter = -1;
                if (extraFlag == 1) {
                    while (parameter < 0) {
                        std::cout << "\n  ~~~ INPUT THE UP BORDER VALUE: ";
                        std::cin >> parameter;
                    }
                    p.find(parameter, 0);
                    std::cout << "  ...Complete\n  RESULT SEQUENCE: " << p << "\n";
                }
                if (extraFlag == 2) {
                    while (parameter < 0) {
                        std::cout << "\n  ~~~ INPUT THE COUNT VALUE: ";
                        std::cin >> parameter;
                    }
                    p.find(parameter, 1);
                    std::cout << "  ...Complete\n  RESULT SEQUENCE: " << p << "\n";
                }
                if (extraFlag == 3) {
                    p.find(100, 0);
                    std::cout << "  ...Complete\n  RESULT SEQUENCE: " << p << "\n";
                }
                answerFlag = 7;
                break;
            }

            case 4:
                std::cout << "\n...Complete\nCURRENT CONTAINER: ";
                std::cout << p;
                std::cout << std::endl;
                answerFlag = 7;
                break;

            case 5: {
                p.fileOutput(argv[1], 1);
                std::cout << "\n...Complete\nSUPER PRIMES: ";
                p.displayOutput(1);
                std::cout << std::endl;
                answerFlag = 7;
                break;
            }

            case 6: {
                p.fileOutput(argv[1], 2);
                std::cout << "\n...Complete\nSOPHIE PRIMES: ";
                p.displayOutput(2);
                std::cout << std::endl;
                answerFlag = 7;
                break;
            }
        }
    }
}

int main(int argc, char** argv) {
    menu(argc, argv);

    return 0;
}