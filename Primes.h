#ifndef PRIMES_H
#define PRIMES_H
#include<stdint.h>
#include<istream>
#include <vector>
#include "ordinaryFunctions.h"

class Primes {
   private:
    std::vector<uint64_t> nums;

   public:
    Primes(uint64_t max_t){
        for(size_t i = 0; i < max_t; ++i){
            if(i!= 0 && (i == 1 || isPrime(i, 2))) nums.push_back(i);
        }
    };

    friend std::ostream &operator<<(std::ostream &out, const Primes &p){
        for(auto it = p.nums.begin(); it != p.nums.end(); ++it){
            std::cout << *it << " ";
        }
    }
};

#endif  //PRIMES_H