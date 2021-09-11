#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class Grid {
    private:
        int width, height;
        int** arr = 0;
    public:
        Grid(int h, int w);
        int getWidth();
        int getHeight();
        void initArray();
        void printGrid();
        void updateGrid(int, int);
        //int** getGrid() {return arr};
        
};


#endif