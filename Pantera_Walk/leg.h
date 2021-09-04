#ifndef LEG_H
#define LEG_H

#include <mutex>
#include <thread>
#include <string>

using namespace std;

void sleep();

class Leg{
    string which;
    string message;
    thread t;
public:
    Leg * next_leg;
    mutex mtx;

    Leg(string which, string message);
    
    void walk();
    void step();
};

#endif