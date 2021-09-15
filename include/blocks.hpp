#ifndef BLOCKS_H_INCLUDED
#define BLOCKS_H_INCLUDED

#include <string>
#include <vector>

#include <tetromino.hpp>

using namespace std;


class Blocks {
    private:
        int const height = 20;
        int const width = 10;
        vector<vector<int>> B;
    public:
        Blocks();
        void addBlocks(Tetromino *);
      
};

#endif