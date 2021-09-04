#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <thread>
#include "prime_calculator.h"

PrimeCalculator::PrimeCalculator(){
    primes.push_back(1);
    primes.push_back(2);
    primes.push_back(3);
    current = 3;

    pause();
}

void PrimeCalculator::start(){
    mtx.unlock();
}

void PrimeCalculator::pause(){
    mtx.lock();
}

void PrimeCalculator::show_latest(){
    cout << "PrimeCalculator results:" << endl; 
    cout << "\tprimes calculcted - " << primes.size() << endl;
    cout << "\tlast prime - " << primes.back() << endl;
    cout << "\tcurrent candidate - " << current << endl;
}

void PrimeCalculator::iterate(){
    mtx.lock();
    current += 2;
    vector<int>::iterator it;
    for (it = primes.begin() + 2; it != primes.end(); ++it){
        this->sleep();

        int denominator = *it;
        if (current % *it == 0){
            mtx.unlock();
            return;
        }
        if (denominator*denominator >= current)
            break;
    }

    primes.push_back(current);
    mtx.unlock();
}

void PrimeCalculator::sleep(){
    chrono::milliseconds timespan(DELAY_MILLISECONDS);
    this_thread::sleep_for(timespan);
}