#include <iostream>

using namespace std;


class CustomGraph{

    private:

    int** Matrix;
    int numOfVertices;

    public:

    CustomGraph(int numOfVertices){
        this -> numOfVertices = numOfVertices;

        Matrix = new int* [numOfVertices];
        for (int i = 0; i < numOfVertices; i++)
        {
            Matrix[i] = new int[numOfVertices];

            for (int j = 0; j < numOfVertices; j++)
            {
                Matrix[i][j] = 0;
            }
            
        }

        
    }

    void AddEdge(int i, int j){
        Matrix[i][j] = 1;
        Matrix[j][i] = 1;
    }

    void RemoveEdge(int i, int j){
        Matrix[i][j] = 0;
        Matrix[j][i] = 0;
    }
    

};