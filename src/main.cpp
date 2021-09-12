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
    Tetromino * tetrominoPointer;
    tetrominoPointer = &tetromino;

    const int tick = 1000;
    atomic_bool * boolPointer;
    boolPointer = &done;

    Grid grid(boolPointer);
    grid.updateTetromino(tetrominoPointer);
    Grid * gridPointer;
    gridPointer = &grid;

    InputThread inputThread (gridPointer, boolPointer, tetrominoPointer);
    InputThread * inputThreadPointer; 
    inputThreadPointer = &inputThread;
    

    thread t (&InputThread::checkInput, inputThreadPointer);
    t.detach();
    //system("clear");
    //grid.printGrid();
    while (!done) {
        grid.updateGrid(1);
        grid.printGrid();
        this_thread::sleep_for(chrono::milliseconds(tick));
    }
    cout <<"ended\n";
    system("stty echo");
    return 0;
  
}
