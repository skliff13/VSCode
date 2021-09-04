#include <iostream>
#include <chrono>
#include "leg.h"
#include "common.h"

using namespace std;

Leg::Leg(string which, string message, mutex * main_mtx){
    this->which = which;
    this->message = message;
    this->main_mtx = main_mtx;
    mtx.lock();

    t = thread(Leg::walk, this);
}

void Leg::walk(){
    while (true){
        step();
    }
}

void Leg::step(){
    mtx.lock();
    //cout << "(DBG) " << which << " unlocked" << endl;
    main_mtx->lock();
    cout << which << " leg up" << endl;
    sleep();
    cout << "\t" << message << endl;
    sleep();
    cout << which << " leg down" << endl;
    //cout << "(DBG) " << "Unlocking main" << endl;
    main_mtx->unlock();
    //cout << "(DBG) " << which << " self-locking" << endl;
    //mtx.lock();
}
