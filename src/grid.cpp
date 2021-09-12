#include <iostream>
#include <vector>
#include <algorithm>
#include <tetromino.hpp>
#include <grid.hpp>
#include <cstdlib>

using namespace std;

Grid::Grid(atomic_bool * d) {
    done = d;
    initArray();
}

int Grid::getHeight() {
    return height;
}

int Grid::getWidth() {
    return width;
}

void Grid::updateTetromino(Tetromino t) {
    tetromino = t;
}


void Grid::initArray() {
    arr = new int*[height];
    for (int i = 0; i < height; ++i)
      {
            arr[i] = new int[width];
    
            for (int j = 0; j < width; ++j)
            {
                if (i == 0 || i == maxH) {
                    arr[i][j] = 1;
                } else if (j == 0 || j == maxW) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }

                
            }
      }
}

void Grid::printGrid() {
    
    for (int r=0; r<height; ++r) {
        for (int c=0; c<width; ++c) {
            cout << arr[r][c];
        }
        cout << endl;
    } 
   
}

void Grid::updateGrid() {
    // /vector<vector<int>> coords = tetromino.getCoords();
    bool end = false;
    for (int i = 1; i >=0; --i) {
        for (vector<int> b: tetromino.getCoords()) {
            arr[b[0] - i][b[1]] = abs(1-i);    
        }
    }
    for (int i=0; i<4; ++i) {
        if ((tetromino.getCoords()[i][0] + 1) == maxH) {
            *done = true;
        }
    }
    
}



