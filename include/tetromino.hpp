#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED

#include <string>
#include <map>
#include <vector>
using namespace std;


// vector<vector<int>> a = {{2, 2}, {2, 2}, {4, 1}, {5, 1}};
// vector<vector<int>> b = {{2, 2}, {3, 2}, {3, 2}, {4, 2}};
// vector<vector<int>> c = {{4, 2}, {3, 2}, {3, 2}, {2, 2}};
// vector<vector<int>> d = {{2, 3}, {2, 2}, {3, 1}, {4, 1}};
// vector<vector<int>> e = {{4, 3}, {4, 2}, {3, 1}, {2, 1}};
// vector<vector<int>> f = {{2, 3}, {3, 3}, {3, 2}, {4, 1}};
// vector<vector<int>> g = {{2, 2}, {3, 2}, {2, 2}, {3, 2}};

class Tetromino {
    private:
        vector<vector<int>> coords;
        
        map<string, vector<vector<int>>> typemap = { 
        {"I", {{2, 2}, {2, 2}, {4, 1}, {5, 1}}},
        {"S", {{2, 2}, {3, 2}, {3, 2}, {4, 2}}},
        {"Z", {{4, 2}, {3, 2}, {3, 2}, {2, 2}}},
        {"J", {{2, 3}, {2, 2}, {3, 1}, {4, 1}}},
        {"L", {{4, 3}, {4, 2}, {3, 1}, {2, 1}}},
        {"T", {{2, 3}, {3, 3}, {3, 2}, {4, 1}}},
        {"O", {{2, 2}, {3, 2}, {2, 2}, {3, 2}}}
        };
        string types[7] = {"I", "S", "Z", "J", "L", "T", "O"};
        string type;
        string getType();
        void setCoords();
    public:
        Tetromino(string);
        int* getCoords();
        void moveDown();
        string toString();
};  

#endif