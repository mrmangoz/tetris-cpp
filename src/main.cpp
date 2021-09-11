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
#include <map>
#include <grid.hpp>
#include <vector>
//#include <thread.hpp>
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
    //vector<int> v = {1, 2};
    // vector<vector<int>> v = {{1, 2}, {3, 4}};
    // for (vector<int> i: v) {
    //     for (int j: i) {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    Tetromino tetromino ("J");
    //Tetromino * tp;
    //tp = &tetromino;
    const int tick = 1000;
    atomic_bool * boolPointer;
    boolPointer = &done;

    Grid grid (20, 10);
    Grid * gridPointer;
    gridPointer = &grid;

    InputThread * itp = new InputThread(gridPointer, boolPointer);
    //InputThread it (gridPointer, boolPointer);

    
    //thread t (&Tetromino::moveDown, tp);
    //thread t (&InputThread::checkInput, itp);
    //t.detach();

    //system("clear");
    //cout << tetromino.toString();
    // cout << tetromino.toString() << endl;
    // tetromino.moveDown();
    // cout << tetromino.toString() << endl;
    while (!done) {
        //grid.printGrid();
        cout << tetromino.toString();
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(tick));
        tetromino.moveDown();
        
        
        //t::sleep_for(chrono::milliseconds(tick));
        //this_thread::sleep_for(chrono::milliseconds(tick));
        //system("clear");
    }
    
    return 0;
  
}
