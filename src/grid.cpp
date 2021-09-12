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

void Grid::updateTetromino(Tetromino * t) {
    tetromino = t;
}

void Grid::initArray() {
    arr = new int*[height];
    for (int i = 0; i < height; ++i) {
        arr[i] = new int[width];
    
        for (int j = 0; j < width; ++j) {
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
    system("clear");

    for (int r=0; r<height; ++r) {
        for (int c=0; c<width; ++c) {
            cout << arr[r][c];
        }
        cout << endl;
    } 
}
void Grid::updateGrid(int check) {
    if (check == 1) {
        updateDown();
    } else if (check == 2) {
        updateLeft();
    } else if (check == 3) {
        updateRight();
    }
}
void Grid::updateDown() {
    tetromino->moveDown();

    for (int i = 1; i >=0; --i) {
        for (vector<int> b: tetromino->getCoords()) {
            arr[b[0] - i][b[1]] = abs(1-i);    
        }
    }

    for (int i=0; i<4; ++i) {
        if ((tetromino->getCoords()[i][0] + 1) == maxH) {
            *done = true;
        }
    } 
}

void Grid::updateLeft(){
    bool move = true;
    for (int j=0; j<4; ++j) {
        if ((tetromino->getCoords()[j][1] - 1) == minW) {
            move = false;
            break;
        } else {
            move = true;
        }
    }
    if (move) {
        tetromino->moveLeft();
        for (int i = 1; i >=0; --i) {
            for (vector<int> b: tetromino->getCoords()) {
                arr[b[0]][b[1] + i] = abs(1-i);    
            }
        } 
    }
}

void Grid::updateRight() {
    bool move = true;
    for (int j=0; j<4; ++j) {
        if ((tetromino->getCoords()[j][1] + 1) == maxW) {
            move = false;
            break;
        } else {
            move = true;
        }
    }
    if (move) {
        tetromino->moveRight();
        for (int i = 1; i >=0; --i) {
            for (vector<int> b: tetromino->getCoords()) {
                arr[b[0]][b[1] - i] = abs(1-i);    
            }
        } 
    }
}


