#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED

using namespace std;
#include <atomic>
#include <grid.hpp>
#include <tetromino.hpp>

class InputThread {
    private:
        atomic_bool * done;
        Grid * grid;
        Tetromino * tetromino;
        int rowCount = 0;
    public:
        InputThread(Grid * , atomic_bool *, Tetromino *);
        void checkInput();
        char getKey();
        void updateRowCount();
};

#endif