
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <algorithm>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>

const int ROWS = 10;
const int COLS = 10;

// A cell in the maze
struct Cell {
    int row;
    int col;
    bool visited;
    bool top;
    bool bottom;
    bool left;
    bool right;
};

// A graph representation of the maze
struct Maze {
    std::vector<Cell> cells;
    std::vector<std::vector<int>> adjacencyList;
};

// Generate a random maze using a depth-first search algorithm
Maze generateMaze() {
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

    // Initialize adjacency list
    maze.adjacencyList.resize(ROWS * COLS);

    // Use a depth-first search algorithm to generate the maze
    std::vector<int> stack;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    int start = 0;
    stack.push_back(start);
    maze.cells[start].visited = true;
   
    while (!stack.empty()) {
    int current = stack.back();
    std::vector<int> neighbors;
    int row = current / COLS;
    int col = current % COLS;
    if (row > 0 && !maze.cells[current - COLS].visited) {
        neighbors.push_back(current - COLS);
    }
    if (row < ROWS - 1 && !maze.cells[current + COLS].visited) {
        neighbors.push_back(current + COLS);
    }
    if (col > 0 && !maze.cells[current - 1].visited) {
        neighbors.push_back(current - 1);
    }
    if (col < COLS - 1 && !maze.cells[current + 1].visited) {
        neighbors.push_back(current + 1);
    }
    if (neighbors.empty()) {
        stack.pop_back();
    } else {
        std::shuffle(neighbors.begin(), neighbors.end(), gen);
        int next = neighbors[0];
        stack.push_back(next);
        maze.cells[next].visited = true;
        int nextRow = next / COLS;
        int nextCol = next % COLS;
        if (nextRow < row) {
            maze.cells[current].top = false;
            maze.cells[next].bottom = false;
        } else if (nextRow > row) {
            maze.cells[current].bottom = false;
            maze.cells[next].top = false;
        } else if (nextCol < col) {
            maze.cells[current].left = false;
            maze.cells[next].right = false;
        } else if (nextCol > col) {
            maze.cells[current].right = false;
            maze.cells[next].left = false;
        }
        maze.adjacencyList[current].push_back(next);
        maze.adjacencyList[next].push_back(current);
    }
}



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the graphics scene and view
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    // Add a rect item for each cell in the maze
    for (int i = 0; i < maze.cells.size(); i++) {
        int row = maze.cells[i].row;
        int col = maze.cells[i].col;
        int x = col * CELL_SIZE;
        int y = row * CELL_SIZE;
        QGraphicsRectItem *item = new QGraphicsRectItem(x, y, CELL_SIZE, CELL_SIZE);
        scene.addItem(item);
    }

    // Set up the view and show the window
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Maze");
    view.resize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
    view.show();

    return app.exec();
}



class MazeView : public QGraphicsView {
    Q_OBJECT

public:
    MazeView(QGraphicsScene *scene, QWidget *parent = 0) : QGraphicsView(scene, parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) {
        // Get the position of the mouse click
        int x = event->pos().x();
        int y = event->pos().y();

        // Calculate the row and column of the clicked cell
        int row = y / CELL_SIZE;
        int col = x / CELL_SIZE;

        // Get the index of the clicked cell in the maze's adjacency list
        int index = row * COLS + col;

        // Call the maze solving algorithm to find the shortest path between the clicked cell and the end cell
        std::vector<int> path = solveMaze(maze, index, endIndex);

        // Draw the solution on the screen
        for (int i = 0; i < path.size(); i++) {
            int r = path[i] / COLS;
            int c = path[i] % COLS;
            int x = c * CELL_SIZE;
            int y = r * CELL_SIZE;
            QGraphicsRectItem *item = new QGraphicsRectItem(x, y, CELL_SIZE, CELL_SIZE);
            item->setBrush(Qt::red);
            scene()->addItem(item);
        }
    }
};

int main(int argc, char *argv[]) {
    // ...

    // Create the view and set it as the scene's view
    MazeView view(&scene);
    scene.setParent(&view);

    // ...

    return app.exec();
}


