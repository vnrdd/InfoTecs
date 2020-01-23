#ifndef PRIMES_H
#define PRIMES_H
#include<stdint.h>
#include<istream>
#include <set>
#include "ordinaryFunctions.h"

class Primes {
   private:
    std::set<uint64_t> nums;

   public:
    Primes(uint64_t max_t){
        for(size_t i = 0; i < max_t; ++i){
            if(i != 0 && (i == 1 || isPrime(i, 2))) nums.insert(i);
        }
    };

    uint64_t size(){
        return nums.size();
    };

    uint64_t operator[](int index){
        auto it = nums.begin();
        for(size_t i = 0; i < index; ++i){
            it++;
        }
        uint64_t el = *it;
        return el;
    };

    friend std::ostream &operator<<(std::ostream &out, const Primes &p){
        for(auto it = p.nums.begin(); it != p.nums.end(); ++it){
            std::cout << *it << " ";
        }
    };
};

#endif  //PRIMES_H