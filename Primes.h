#ifndef PRIMES_H
#define PRIMES_H
#include <stdint.h>
#include <istream>
#include <set>
#include "ordinaryFunctions.h"

class Primes {
   private:
    std::set<uint64_t> nums;
    uint64_t max;

   public:
    class iterator : std::set<uint64_t>::iterator {
       public:
        std::set<uint64_t>::iterator iter;
        iterator &operator++() {
            iter++;
            return *this;
        };
    };

    /*Primes::iterator begin() {
        iterator it;
        auto beg = nums.begin();
        it.iter = beg;
        return it;
    };

    Primes::iterator end() {
        iterator it;
        auto en = nums.end();
        it.iter = en;
        return it;
    };*/

    std::pair<Primes::iterator, bool> insert(uint64_t value) {
        iterator it;
        it.iter = nums.begin();
        if (max == 0 || isPrime(value, 2) == 0) return std::make_pair(it, 0);
        nums.insert(value);
        it.iter = nums.find(value);
        return std::make_pair(it, 1);
    }

    Primes(uint64_t max_t) {
        max = max_t;
        for (size_t i = 1; i < max_t; ++i) {
            insert(i);
        }
    };

    Primes() {
        max = 0;
    };

    uint64_t size() {
        return nums.size();
    };

    uint64_t operator[](uint64_t index) {
        auto it = nums.begin();
        for (size_t i = 0; i < index; ++i) {
            it++;
        }
        uint64_t el = *it;
        return el;
    };

    friend std::ostream &operator<<(std::ostream &out, const Primes &p) {
        for (auto it = p.nums.begin(); it != p.nums.end(); ++it) {
            std::cout << *it << " ";
        }
        return out;
    };

    ~Primes(){};
};

#endif  //PRIMES_H