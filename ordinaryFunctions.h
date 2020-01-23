#ifndef ORDINARYFUNCTIONS_H
#define ORDINARYFUNCTIONS_H
#include<iostream>

int isPrime(int a, int i) {
    return i * i <= a ? (a % i) && isPrime(a, i + 1) : 1;
}

#endif //ORDINARYFUNCTIONS_H