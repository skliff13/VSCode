#include <iostream>
#include <string>
#include <thread>
#include "prime_calculator.h"

using namespace std;

void calc_task(PrimeCalculator * pc){
    while (true)
        pc->iterate();
}

int main(){
    cout << "Hello! This script calculates prime numbers." << endl;
    cout << "Available commands: start, show, pause, exit" << endl;

    PrimeCalculator pc;
    thread calc_thread(calc_task, &pc);

    while (true){
        string command;
        cin >> command;
        if (command == "start") {
            cout << "Staring the calculation" << endl;
            pc.start();
        }
        else if (command == "show") {
            cout << "Showing the latest result" << endl;
            pc.show_latest();
        }
        else if (command == "pause") {
            cout << "Pausing the calculation" << endl;
            pc.pause();
        }
        else if (command == "exit") {
            cout << "Exiting" << endl;
            return 0;
        }
        else {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}