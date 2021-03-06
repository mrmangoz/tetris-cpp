#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <tetromino.hpp>
#include <atomic>

class Grid {
    private:
        const int width = 12;
        const int height = 22;
        int** arr = 0;
        atomic_bool * done;
        const int maxH = height - 1;
        const int maxW = width - 1;
        const int minW = 0;
        const int minH = 0;
        bool checkDown();
        bool checkLeft();
        bool checkRight();
        bool checkRotate(int, int);
    public:
        Grid(atomic_bool *);
        void updateDown();
        void updateLeft();
        void updateRight();
        void updateRotate(int, int);
        int getWidth();
        int getHeight();
        void initArray();
        void printGrid();
        void updateTetromino(Tetromino *);
        Tetromino * tetromino;
};

#endif