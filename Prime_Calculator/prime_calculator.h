#ifndef PRIME_CALCULATOR_H
#define PRIME_CALCULATOR_H

#include <vector>
#include <mutex>
using namespace std;

class PrimeCalculator {
    const static int DELAY_MILLISECONDS = 100;
    vector<int> primes;
    int current;
    mutex mtx;

public:
    PrimeCalculator();

    void start();
    void pause();
    void show_latest();
    void iterate();

private:
    void sleep();
};

#endif
