#include <grid.hpp>
#include <checkInput.hpp>

#include <stdio.h>
#include <atomic>
#include <unistd.h>
#include <termios.h>





using namespace std;


InputThread::InputThread(Grid * g, atomic_bool * d){
        done = d;
        grid = g; 
        //checkInput();      
}

void InputThread::updateRowCount() {
    ++rowCount;
}
void InputThread::checkInput() {
    while (!*done) {
        int input = getKey();
        if (input == 113) {
            *done = true;
        }
        if (input == 100) {
            grid->updateGrid(rowCount,0);
            updateRowCount();
        }
    }
}


char InputThread::getKey() {
        // code from https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}