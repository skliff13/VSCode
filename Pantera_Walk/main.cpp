#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <string>

#define DELAY_MILLISECONDS 750 

using namespace std;

void sleep(){
    chrono::milliseconds timespan(DELAY_MILLISECONDS);
    this_thread::sleep_for(timespan);
}

class Leg{
    string which;
    string message;
    thread t;
public:
    Leg * next_leg;
    mutex mtx;

    Leg(string which, string message){
        this->which = which;
        this->message = message;
        mtx.lock();

        t = thread(Leg::walk, this);
    }

    void walk(){
        while (true){
            step();
        }
    }

    void step(){
        mtx.lock();
        cout << which << " leg up" << endl;
        sleep();
        cout << "\t" << message << endl;
        sleep();
        cout << which << " leg down" << endl;
        next_leg->mtx.unlock();
    }
};

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