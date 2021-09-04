#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <string>
#include "leg.h"
#include "common.h"

using namespace std;


int main(){
    Leg leg1("Front left", "RE!");
    Leg leg2("Front right", "SPECT!");
    Leg leg3("Back left", "WALK!");
    Leg leg4("Back right", "WHAT DID YOU SAY?!");

    leg1.next_leg = &leg2;
    leg2.next_leg = &leg3;
    leg3.next_leg = &leg4;
    leg4.next_leg = &leg1;
    
    leg1.mtx.unlock();

    while (true){
        sleep();
    }

    return 0;
}