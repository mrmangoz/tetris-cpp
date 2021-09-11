#include <tetromino.hpp>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Tetromino::Tetromino(string t) {
    type = t;
    setCoords();
}

void Tetromino::setCoords() {
    coords = typemap[getType()];
}

string Tetromino::getType() {
    return type;
}

void Tetromino::moveDown() {
    for (vector<int> &b: coords) {
        ++b[1];
    }
}

string Tetromino::toString() {
    string output = "";
    //int count = 1;
    for (vector<int> b: coords){
        int count = 1;
        if ((count % 4) == 0) {
            output += to_string(b[1]) + "\n";
            ++count;
        } else {
            output += to_string(b[1]) + " ";
            ++count;
        }
    }
    return output;
}