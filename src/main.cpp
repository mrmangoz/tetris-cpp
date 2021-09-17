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

atomic_bool done(false);

int main() {
    Tetromino tetromino ("Z");
    Tetromino * tetrominoPointer;
    tetrominoPointer = &tetromino;

    const int TICK = 500;
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

    while (!done) {
        grid.updateDown();
        grid.printGrid();
        this_thread::sleep_for(chrono::milliseconds(TICK));
    }
    cout <<"ended\n";
    system("stty echo");
    return 0;
  
}
