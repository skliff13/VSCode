#include <chrono>
#include <thread>
#include "common.h"

using namespace std;

void sleep(){
    chrono::milliseconds timespan(DELAY_MILLISECONDS);
    this_thread::sleep_for(timespan);
}
