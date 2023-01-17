#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <unordered_set>

const int WIDTH = 640;
const int HEIGHT = 480;
const int CELL_SIZE = 40;
const int COLUMNS = WIDTH / CELL_SIZE;
const int ROWS = HEIGHT / CELL_SIZE;

struct Cell
{
    int row;
    int column;
    bool visited = false;
    std::unordered_set<Cell*> neighbors;
};

std::vector<std::vector<Cell>> cells(COLUMNS, std::vector<Cell>(ROWS));

sf::RectangleShape wall(sf::Vector2f(CELL_SIZE, CELL_SIZE));

void initCells()
{
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cells[i][j].row = i;
            cells[i][j].column = j;
            if (i > 0)
            {
                cells[i][j].neighbors.insert(&cells[i - 1][j]);
            }
            if (i < COLUMNS - 1)
            {
                cells[i][j].neighbors.insert(&cells[i + 1][j]);
            }
            if (j > 0)
            {
                cells[i][j].neighbors.insert(&cells[i][j - 1]);
            }
            if (j < ROWS - 1)
            {
                cells[i][j].neighbors.insert(&cells[i][j + 1]);
            }
        }
    }
}

void createMaze()
{
    std::stack<Cell*> cellStack;

    Cell* currentCell = &cells[0][0];
    currentCell->visited = true;
    cellStack.push(currentCell);

    while (!cellStack.empty())
    {
        Cell* nextCell = currentCell;
        std::vector<Cell*> unvisitedNeighbors;

        for (Cell* neighbor : currentCell->neighbors)
        {
            if (!neighbor->visited)
            {
                unvisitedNeighbors.push_back(neighbor);
            }
        }

        if (!unvisitedNeighbors.empty())
        {
            int index = rand() % unvisitedNeighbors.size();
            nextCell = unvisitedNeighbors[index];
            nextCell->visited = true;
            cellStack.push(nextCell);

            currentCell->neighbors.erase(nextCell);
            nextCell->neighbors.erase(currentCell);

            currentCell = nextCell;
        }
        else
        {
            currentCell = cellStack.top();
            cellStack.pop();
        }
    }
}

int main()
{
    srand(time(0));

    sf::RenderWindow
    window(sf::VideoMode(WIDTH, HEIGHT), "Maze");

    wall.setFillColor(sf::Color::White);

initCells();
createMaze();

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();

    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            Cell cell = cells[i][j];
            sf::Vector2f position(cell.column * CELL_SIZE, cell.row * CELL_SIZE);

            for (Cell* neighbor : cell.neighbors)
            {
                if (neighbor->row > cell.row)
                {
                    wall.setPosition(position.x, position.y + CELL_SIZE);
                    window.draw(wall);
                }
                else if (neighbor->row < cell.row)
                {
                    wall.setPosition(position.x, position.y);
                    window.draw(wall);
                }
                else if (neighbor->column > cell.column)
                {
                    wall.setPosition(position.x + CELL_SIZE, position.y);
                    window.draw(wall);
                }
                else if (neighbor->column < cell.column)
                {
                    wall.setPosition(position.x, position.y);
                    window.draw(wall);
                }
            }
        }
    }

    window.display();
}

return 0;
