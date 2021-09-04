#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <string>
#include <map>
#include "leg.h"
#include "common.h"

using namespace std;


int main(){
    mutex main_mtx;
    Leg leg1("Front left", "RE!", &main_mtx);
    Leg leg2("Front right", "SPECT!", &main_mtx);
    Leg leg3("Back left", "WALK!", &main_mtx);
    Leg leg4("Back right", "WHAT DID YOU SAY?!", &main_mtx);

    map<Leg *, Leg *> next_from;
    next_from[&leg1] = &leg2;
    next_from[&leg2] = &leg3;
    next_from[&leg3] = &leg4;
    next_from[&leg4] = &leg1;
    
    Leg * cur = &leg1;

    while (true){
        //cout << "(DBG) " << "Unlocking " << cur->which << endl;
        cur->mtx.unlock();
        sleep();
        cur->mtx.lock();
        //cout << "(DBG) " << "Main woke up" << endl;
        cur = next_from[cur];
    }

    return 0;
}