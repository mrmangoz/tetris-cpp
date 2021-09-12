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

void Tetromino::setType(string t) {
    type = t;
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
