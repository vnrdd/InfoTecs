#ifndef PRIMES_H
#define PRIMES_H
#include <stdint.h>
#include <istream>
#include <fstream>
#include <set>
#include "ordinaryFunctions.h"
#include "myException.h"

class Primes {
   private:
    std::set<uint64_t> nums;
    uint64_t max;

   public:
    std::set<uint64_t>::iterator begin() {
        return nums.begin();
    }

    std::set<uint64_t>::iterator end() {
        return nums.end();
    }

    std::pair<std::set<uint64_t>::iterator, bool> insert(uint64_t value) {
        if (max == 0 && isPrime(value, 2) == 1) {
            nums.insert(value);
            return std::make_pair(nums.find(value), 1);
        }
        else if(max > 0 && value <= max && isPrime(value, 2) == 1){
            nums.insert(value);
            return std::make_pair(nums.find(value), 1);
        }
        return std::make_pair(end(), 0);
    }

    Primes(uint64_t max_t) {
        max = max_t;
        if(max == 0) throw myException();
        for (size_t i = 1; i <= max_t; ++i) {
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
        if(index < 0) throw myException();
        auto it = nums.begin();
        for (size_t i = 0; i < index; ++i) {
            it++;
        }
        uint64_t el = *it;
        return el;
    };

    void fileOutput(const char *filename, const int &flag){
        std::ofstream f;
        f.open(filename);
        if(flag == 0){
            for(auto it = begin(); it != end(); ++it){
                f << *it << "\n";
            }
        }
        if(flag == 1){
            int i = 0;
            for(auto it = begin(); it != end(); ++it){
                if(isPrime(i, 2)) f << *it << "\n";
                i++;
            }
        }
        if(flag == 2){
            for(auto it = begin(); it != end(); ++it){
                if(isPrime(2*(*it)+1, 2)){
                    f << *it << "\n";
                }
            }
        }
        f.close();
    }

    friend std::ostream &operator<<(std::ostream &out, Primes &p) {
        for (auto it = p.begin(); it != p.end(); ++it) {
            std::cout << *it << " ";
        }
        return out;
    };

    ~Primes(){};
};

#endif  //PRIMES_H