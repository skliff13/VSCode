#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <string>
#include "leg.h"
#include "common.h"

using namespace std;


int main(){
    mutex main_mtx;
    Leg leg1("Front left", "RE!", &main_mtx);
    Leg leg2("Front right", "SPECT!", &main_mtx);
    Leg leg3("Back left", "WALK!", &main_mtx);
    Leg leg4("Back right", "WHAT DID YOU SAY?!", &main_mtx);

    leg1.next_leg = &leg2;
    leg2.next_leg = &leg3;
    leg3.next_leg = &leg4;
    leg4.next_leg = &leg1;
    
    Leg * cur = &leg1;

    while (true){
        //cout << "(DBG) " << "Unlocking " << cur->which << endl;
        cur->mtx.unlock();
        sleep();
        main_mtx.lock();
        main_mtx.unlock();
        //cout << "(DBG) " << "Main woke up" << endl;
        cur = cur->next_leg;
    }

    return 0;
}