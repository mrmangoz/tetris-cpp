#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED

#include <string>
#include <map>
#include <vector>

using namespace std;

class Tetromino {
    private:
        vector<vector<int>> coords;
        map<string, vector<vector<int>>> typemap = { 
        {"I", {{1, 3}, {1, 4}, {1, 5}, {1, 6}}},
        {"J", {{1, 3}, {2, 3}, {2, 4}, {2, 5}}},
        {"L", {{1, 5}, {2, 5}, {2, 4}, {2, 3}}},
        {"O", {{1, 4}, {1, 5}, {2, 5}, {2, 4}}},
        {"S", {{1, 5}, {1, 4}, {2, 4}, {2, 3}}},
        {"T", {{1, 4}, {2, 3}, {2, 4}, {2, 5}}},
        {"Z", {{1, 3}, {1, 4}, {2, 4}, {2, 5}}}
        };
        const string TYPES[7] = {"I", "S", "Z", "J", "L", "T", "O"};
        string types[7] = {"I", "S", "Z", "J", "L", "T", "O"};
        string type;
        string getType();
        void setCoords();
        bool checkMove(int, const int);
        const int minW = 0;
        const int maxW = 11;
    public:
        Tetromino(string);
        Tetromino();
        void setType(string);
        vector<vector<int>> getCoords();
        void moveDown();
        void moveLeft();
        void moveRight();
        void rotate(int, int);
        vector<vector<int>> getRotate(int, int);
        string toString();
};  

#endif