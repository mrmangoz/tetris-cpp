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

string Tetromino::toString() {
    string output = "";
    //int count = 1;
    for (vector<int> b: coords){
        for (int i=0; i<2; i++) {
            output += to_string(b[i]) + " ";
        }
        output += "\n";
    }
    return output;
}
