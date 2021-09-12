#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

#include <thread>
#include <atomic>
#include <chrono>

#include <string>
#include <map>
#include <vector>

#include <grid.hpp>
#include <inputthread.hpp>
#include <tetromino.hpp>

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
    Tetromino tetromino ("Z");
    const int tick = 100;
    atomic_bool * boolPointer;
    boolPointer = &done;

    Grid grid(boolPointer);
    grid.updateTetromino(tetromino);
    Grid * gridPointer;
    gridPointer = &grid;

    InputThread * itp = new InputThread(gridPointer, boolPointer);
    InputThread it (gridPointer, boolPointer);

    thread t (&InputThread::checkInput, itp);
    t.detach();

    
    
    while (!done) {
        system("clear");
        grid.updateGrid();
        grid.printGrid();
        grid.tetromino.moveDown();
        this_thread::sleep_for(chrono::milliseconds(tick));
    }
    cout <<"ended\n";
    system("stty echo");
    return 0;
  
}
