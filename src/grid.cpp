#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include <tetromino.hpp>
#include <grid.hpp>

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
            if (i == maxH) {
                arr[i][j] = -1;
            } else if (j == minW || j == maxW) {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }  
        }
    }
}

void Grid::printGrid() {
    system("clear");
    string out = "";
    for (int r=0; r<height; ++r) {
        for (int c=0; c<width; ++c) {
            //cout << arr[r][c];
            if (r == minH || r == maxH || c == minW || c == maxW) {
                out += "*";
            } else if (arr[r][c] == 0) {
                out += " ";
            } else {
                out += "#"; //to_string(arr[r][c]);
            }
            
        }
        //cout << endl;
        out += "\n";
    } 
    cout << out;
}


bool Grid::checkDown() {
    for (int i=0; i<4; ++i) {
        vector<vector<int>> b = tetromino->getCoords();

        if (arr[b[i][0] + 1][b[i][1]] == -1) {
            return true;
        }
    }
    return false;
}

bool Grid::checkLeft() {
    vector<vector<int>> b = tetromino->getCoords();

    for (int j=0; j<4; ++j) {
        if (arr[b[j][0]][b[j][1] - 1] == -1) {
            return false;
        }
    }
    return true;
}

bool Grid::checkRight() {
    vector<vector<int>> b = tetromino->getCoords();

    for (int j=0; j<4; ++j) {
        if (arr[b[j][0]][b[j][1] + 1] == -1) {
            return false;
        }
    }
    return true;
}

bool Grid::checkRotate(int rx, int ry) {
    
}

void Grid::updateDown() {
    if (checkDown()) {
        vector<vector<int>> b = tetromino->getCoords();
        for (int i=0; i<4; ++i) {
            arr[b[i][0]][b[i][1]] = -1;
        }

        tetromino = new Tetromino("J");

    } else {

        tetromino->moveDown();

        for (int i = 1; i >=0; --i) {
            for (vector<int> b: tetromino->getCoords()) {
                arr[b[0] - i][b[1]] = abs(1-i);    
            }
        }
    }
}

void Grid::updateLeft(){
    if (checkLeft()) {

        tetromino->moveLeft();

        for (int i = 1; i >=0; --i) {
            for (vector<int> b: tetromino->getCoords()) {
                arr[b[0]][b[1] + i] = abs(1-i);    
            }
        } 
    }
}

void Grid::updateRight() {
    if (checkRight()) {

        tetromino->moveRight();

        for (int i = 1; i >=0; --i) {
            for (vector<int> b: tetromino->getCoords()) {
                arr[b[0]][b[1] - i] = abs(1-i);    
            }
        } 
    }
}

void Grid::updateRotate(int rx, int ry) {
    for (vector<int> b: tetromino->getCoords()) {
        arr[b[0]][b[1]] = 0;    
    }

    tetromino->rotate(rx, ry);
    
    for (vector<int> b: tetromino->getCoords()) {
        arr[b[0]][b[1]] = 1;    
    }
}



