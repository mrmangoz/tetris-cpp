#include <grid.hpp>
#include <iostream>
#include <ncurses.h>
using namespace std;

Grid::Grid(int h, int w) {
    height = h;
    width = w;
    initArray();
}

int Grid::getHeight() {
    return height;
}

int Grid::getWidth() {
    return width;
}


void Grid::initArray() {
    arr = new int*[height];
    for (int i = 0; i < height; ++i)
      {
            arr[i] = new int[width];
    
            for (int j = 0; j < width; ++j)
            {
                  arr[i][j] = 0;
            }
      }
}

void Grid::printGrid() {
    
    for (int r=0; r<height; ++r) {
        for (int c=0; c<width; ++c) {
            //cout << arr[r][c];
            //printw("%d", arr[r][c]);
            printw("0");
            //cout << 0;
            
        }
        printw("\n");
        //cout << endl;
    } 
   
}

void Grid::updateGrid(int row, int column) {
    if (row > 0) {
        arr[row -1][column] = 0; 
    }
    arr[row][column] = 1;
}

