#ifndef LEG_H
#define LEG_H

#include <mutex>
#include <thread>
#include <string>

using namespace std;

void sleep();

class Leg{
    string message;
    thread t;
    mutex * main_mtx;
public:
    mutex mtx;
    string which;

    Leg(string which, string message, mutex * main_mtx);
    
    void walk();
    void step();
};

#endif