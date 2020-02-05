#ifndef ORDINARYFUNCTIONS_H
#define ORDINARYFUNCTIONS_H
#include <iostream>

bool checkFile(std::string filename) {
    int i = 0;

    while (filename[i] != '\0') {
        if (filename[i] == '.') {
            if (filename[i + 1] == 't') {
                if (filename[i + 2] == 'x') {
                    if (filename[i + 3] == 't') {
                        if (filename[i + 4] == '\0') {
                            return 1;
                        }
                    }
                }
            }
        }
        i++;
    }
    return 0;
}

int isPrime(int a, int i) {
    if (a == 0 || a == 1) return 0;
    return i * i <= a ? (a % i) && isPrime(a, i + 1) : 1;
}

std::ostream &operator<<(std::ostream &out, std::set<uint64_t> &p) {
    for (auto it = p.begin(); it != p.end(); ++it) {
        std::cout << *it << " ";
    }
    return out;
}

#endif  //ORDINARYFUNCTIONS_H