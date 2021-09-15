#include <blocks.hpp>
#include <tetromino.hpp>

#include <vector>

using namespace std;

Blocks::Blocks() {
    B = vector<vector<int>>(height, vector<int>(width, 0));
}

void Blocks::addBlocks(Tetromino * tetromino) {
    for (vector<int> t: tetromino->getCoords()) {
        B[t[0]][t[1]] = 1;
    }
}