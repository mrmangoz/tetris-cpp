#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <tetromino.hpp>
#include <atomic>
class Grid {
    private:
        int width = 12;
        int height = 22;
        int** arr = 0;
        atomic_bool * done;
        const int maxH = height - 1;
        const int maxW = width - 1;
    public:
        Grid(atomic_bool *);
        int getWidth();
        int getHeight();
        void initArray();
        void printGrid();
        void updateGrid();
        void updateTetromino(Tetromino);
        Tetromino tetromino;
        //void setType(string);
};


#endif