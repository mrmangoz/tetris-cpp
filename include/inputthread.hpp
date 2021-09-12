#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED
using namespace std;
#include <atomic>
#include <grid.hpp>

class InputThread {
    private:
        atomic_bool * done;
        Grid * grid;
        int rowCount = 0;      
    public:
        InputThread(Grid * , atomic_bool *);
        void checkInput();
        char getKey();
        void updateRowCount();
};

#endif