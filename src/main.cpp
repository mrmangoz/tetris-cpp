#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <thread>
#include <atomic>
#include <chrono>

#include <grid.hpp>
//#include <thread.hpp>
#include <checkInput.hpp>
using namespace std;


// string createTemplate() {
//     string header_footer = "***********\n";
//     string body = "";
//     for (int i = 0; i < 22; ++i) {
//         body += "*         *\n";
//     }
//     string output = header_footer + body + header_footer;
//     return output;
    
// }

atomic_bool done(false);




int main() {
    const int tick = 100;
    atomic_bool * boolPointer;
    boolPointer = &done;
    Grid grid (20, 10);
    Grid * gridPointer;
    gridPointer = &grid;
    cout << "testing threads" << endl;
    InputThread * itp = new InputThread(gridPointer, boolPointer);
    InputThread it (gridPointer, boolPointer);
    thread t (&InputThread::checkInput, itp);
    t.detach();
    system("clear");
    while (!done) {
        grid.printGrid();
        this_thread::sleep_for(chrono::milliseconds(tick));
        system("clear");
    }
    return 0;
  
}
