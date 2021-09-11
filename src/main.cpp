#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <grid.hpp>
#include <ncurses.h>
#include <thread>
#include <atomic>
#include <thread.hpp>
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
    
    cout << "testing threads" << endl;
    //runGame();
    thread t (checkInput, ref(done));
    t.detach();
    while (!done) {
        //system("stty cooked");
        cout << "test" << endl;
        
        sleep(1);
    }
    //string in;
    //cin >> in;
    //int ch;
    //system("stty raw");
    
    //system("clear");

    
    // int ch;
    // initscr();
    // raw();
    // bool done = false;
    // Grid grid (20, 10);
    // while (!done) {
    //     ch = getch();
    //     printw("test\n");
    //     refresh();
    //     if (ch == 113) {
    //         done = true;
    //     }
    // }
    // grid.printGrid();
    // refresh();
    // endwin();

    return 0;
  
}
