#include <tetromino.hpp>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Tetromino::Tetromino(string t) {
    type = t;
    setCoords();
}

Tetromino::Tetromino() {

}

void Tetromino::setCoords() {
    coords = typemap[getType()];
}

string Tetromino::getType() {
    return type;
}

vector<vector<int>> Tetromino::getCoords (){
    return coords;
}

void Tetromino::moveDown() {
    for (vector<int> &b: coords) {
        ++b[0];
    }
}

// bool Tetromino::checkMove(int rl, const int minMax) {
//     for (int j=0; j<4; ++j) {
//         if ((getCoords()[j][1] + rl) == minMax) {
            
//             return false;
//         }
//     }
//     return true;
// }

void Tetromino::moveLeft() {
    for (vector<int> &b: coords) {
        --b[1];
    }
}

void Tetromino::moveRight() {
    for (vector<int> &b: coords) {
        ++b[1];
    }
}

void Tetromino::setType(string t) {
    type = t;
}

vector<vector<int>> Tetromino::getRotate(int rx, int ry) {
    // CW  rx =  1, ry = -1
    // ACW rx = -1, ry =  1
    vector<vector<int>> tempCoords = coords;
    int h_x = tempCoords[2][1];
    int h_y = tempCoords[2][0];
    for (vector<int> &b: tempCoords) {
        int x = b[1];
        int y = b[0];
        x -= h_x;
        y -= h_y;
        int swap = y;
        y = rx * x;
        x = ry * swap;
        b[0] = y + h_y ;
        b[1] = x + h_x;
    }
    return tempCoords;
}

void Tetromino::rotate(int rx, int ry) {
    // CW  rx =  1, ry = -1
    // ACW rx = -1, ry =  1
    vector<vector<int>> tempCoords = coords;
    int h_x = tempCoords[2][1];
    int h_y = tempCoords[2][0];
    for (vector<int> &b: tempCoords) {
        int x = b[1];
        int y = b[0];
        x -= h_x;
        y -= h_y;
        int swap = y;
        y = rx * x;
        x = ry * swap;
        b[0] = y + h_y ;
        b[1] = x + h_x;
    }
    coords = tempCoords;
}

string Tetromino::toString() {
    string output = "";
    for (vector<int> b: coords){
        for (int i=0; i<2; i++) {
            output += to_string(b[i]) + " ";
        }
        output += "\n";
    }
    return output;
}
