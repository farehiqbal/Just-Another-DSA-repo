#include <iostream>
#include <vector>


using namespace std;

// firstly we will need to represent maze as graph data structure. We will be using adjency list for that.
// Each cell in the maze is represented by a node/vertex in the graph & edges b/w vertices represent paths.


const int ROWS = 10;
const int COLS = 10;

struct Cell{
    int row;
    int col;
    bool visited;
    bool top;
    bool bottom;
    bool left;
    bool right;

};

class Maze{
    
    vector<Cell> cells;
    vector<vector<int>> adjList;

    void generateMaze(){

        Maze maze;
            // Initialize cells
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                Cell cell;
                cell.row = row;
                cell.col = col;
                cell.visited = false;
                cell.top = true;
                cell.bottom = true;
                cell.left = true;
                cell.right = true;
                maze.cells.push_back(cell);
            }
        }
    }
};

