#ifndef PRIMES_H
#define PRIMES_H
#include <stdint.h>
#include <fstream>
#include <istream>
#include <set>
#include <stdexcept>
#include "ordinaryFunctions.h"

/*!
    \brief It is the class-container for working with prime numbers.
*/

class Primes {
   private:
    std::set<uint32_t> nums;
    uint32_t max;

   public:
    /*! Begin iterator */
    std::set<uint32_t>::iterator begin() {
        return nums.begin();
    }
    /*! End iterator */
    std::set<uint32_t>::iterator end() {
        return nums.end();
    }

    /*! Method for pushing values into the container */
    std::pair<std::set<uint32_t>::iterator, bool> insert(uint32_t value) {
        if (max == 0 && isPrime(value, 2) == 1) {
            nums.insert(value);
            return std::make_pair(nums.find(value), 1);
        } else if (max > 0 && value <= max && isPrime(value, 2) == 1) {
            nums.insert(value);
            return std::make_pair(nums.find(value), 1);
        }
        return std::make_pair(end(), 0);
    }

    /*! Method for popping values from the container */
    size_t erase(const uint32_t &value) {
        return nums.erase(value);
    }

    /*! Upborder container constructor */
    Primes(uint32_t max_t) {
        max = max_t;
        for (size_t i = 1; i <= max_t; ++i) {
            insert(i);
        }
    };

    /*! Empty container constructor */
    Primes() {
        max = 0;
    };

    bool operator==(Primes &s) {
        if (nums == s.nums) return 1;
        return 0;
    }

    /*! Returning value is the container size */
    uint32_t size() {
        return nums.size();
    };

    /*! [] Operator for taking values */
    uint32_t operator[](uint32_t index) {
        if (index < 0 || index > size() - 1) throw std::exception();
        auto it = nums.begin();
        for (size_t i = 0; i < index; ++i) {
            it++;
        }
        uint32_t el = *it;
        return el;
    };

    /*! Method for outputting our container into the file (flags exist: 1-full; 2-superprimes; 3-sophie primes) */
    void fileOutput(std::string filename, int flag) {
        std::ofstream f;
        f.open(filename);
        if (flag == 0) {
            for (auto it = begin(); it != end(); ++it) {
                f << *it << "\n";
            }
        }
        if (flag == 1) {
            auto isSuper = [](uint32_t value, uint32_t index) {
                if (isPrime(value, 2) && isPrime(index, 2)) return 1;
                return 0;
            };

            int i = 0;
            for (auto it = begin(); it != end(); ++it) {
                if (isSuper(*it, i + 1)) f << *it << "\n";
                i++;
            }
        }
        if (flag == 2) {
            auto isSophie = [](uint32_t value) {
                if (isPrime(value, 2) && isPrime(2 * value + 1, 2)) return 1;
                return 0;
            };

            for (auto it = begin(); it != end(); ++it) {
                if (isSophie(*it)) {
                    f << *it << "\n";
                }
            }
        }
        f.close();
    }

    /*! Method for outputting our container on the display (flags exist: 1-full; 2-superprimes; 3-sophie primes) */
    void displayOutput(int flag) {
        if (flag == 1) {
            auto isSuper = [](uint32_t value, uint32_t index) {
                if (isPrime(value, 2) && isPrime(index, 2)) return 1;
                return 0;
            };

            int i = 0;
            for (auto it = begin(); it != end(); ++it) {
                if (isSuper(*it, i + 1)) std::cout << *it << " ";
                i++;
            }
        }
        if (flag == 2) {
            auto isSophie = [](uint32_t value) {
                if (isPrime(value, 2) && isPrime(2 * value + 1, 2)) return 1;
                return 0;
            };

            for (auto it = begin(); it != end(); ++it) {
                if (isSophie(*it)) std::cout << *it << " ";
            }
        }
    }

    /*! Copy constructor */
    Primes(const Primes &copy) {
        max = copy.max;
        nums = copy.nums;
    }

    void find() {
        clear();
        for (int i = 0; i < 100; ++i) {
            if (isPrime(i, 2)) insert(i);
        }
    }

    /*! Method for finding and memorizing the sequence */
    void find(uint64_t count_or_max, bool flag) {
        if (flag == 0 && count_or_max < 2) return;
        if (flag == 0) {
            clear();
            for (int i = 0; i < count_or_max; ++i) {
                if (isPrime(i, 2)) insert(i);
            }
            return;
        }

        if (flag == 1) {
            clear();
            int j = 0;
            for (int i = 0; i < count_or_max;) {
                if (isPrime(j, 2)) {
                    insert(j);
                    i++;
                }
                j++;
            }
            return;
        }
    }

    /*! Default output operator */
    friend std::ostream &operator<<(std::ostream &out, Primes &p) {
        for (auto it = p.begin(); it != p.end(); ++it) {
            std::cout << *it << " ";
        }
        return out;
    };

    /*! Method Clear */
    void clear() {
        nums.clear();
        max = 0;
    }

    /*! Destructor */
    ~Primes(){};
};

#endif  //PRIMES_H