#include <iostream>

using namespace std;
#include <bits/stdc++.h>

const int Nodes = 6;
// const int Edges = 7;

int findMinV(int distance[], bool visited[]){

    int minV = INT_MAX;
    int minIndex;
    // int length = sizeof(distance) / sizeof(distance[0]);
    for (int i = 0; i < Nodes; i++)
    {
        if(visited[i] == false && distance[i] <= minV){
            minV = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}


void Dijkstras(int adjMatrix[Nodes][Nodes], int sourceNode){

    int vertex = Nodes;
    
    bool visited[vertex];
    int distance[vertex];

    // distance[sourceNode] = 0;

    for (int i = 0; i < vertex; i++)
    {
        // if(i == sourceNode) continue;
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[sourceNode] = 0;


    for (int i = 0; i < vertex; i++)
    {
        int minV = findMinV(distance, visited);
        visited[minV] = true;

        for (int j = 0; j < vertex; j++)
        {
            if(adjMatrix[minV][j] != 0 && visited[j] == false && distance[minV] != INT_MAX){
                
                int tempDistance = distance[minV] + adjMatrix[minV][j];

                if (tempDistance < distance[j]){
                    distance[j] = tempDistance;
                }
            }

            //  if (!visited[j] && adjMatrix[minV][j]
            //     && distance[minV] != INT_MAX
            //     && distance[minV] + adjMatrix[minV][j] < distance[j])
            //     distance[j] = distance[minV] + adjMatrix[minV][j];
        }
        
    }

    for (int i = 0; i < Nodes; i++)
    {
        cout << distance[i] << " ";
    }
    

}

 void bfs(int adjMatrix[Nodes][Nodes], int sourceNode){

        queue<int> queue;
        bool visited[Nodes];

        for (int i = 0; i < Nodes; i++)
        {
            visited[i] = false;
        }
        


        queue.push(sourceNode);
        visited[sourceNode] = true;

        int output;

        while(!queue.empty()){

            output = queue.front();
            queue.pop();
            cout << output;

            // queue.pop();

            for (int i = 0; i < Nodes; i++)
            {
                if(adjMatrix[output][i] != 0 && visited[i] == false){
                    // cout << i;
                    
                    visited[i] = true;
                    queue.push(i);
                }
            }
            
        }
        
    }



int main(){

    // int adjMatrix[Nodes][Nodes]; 

    //     for (int i = 0; i < Edges; i++)
    //     {
    //         int Node1;
    //         int Node2;
    //         int weight;
    //         cout << "Enter previous node";
    //         cin >> Node1;
    //         cout << "Enter next node";
    //         cin >> Node2;
    //         cout << "Enter weight between these nodes";
    //         cin >> weight;

    //         adjMatrix[Node1][Node2] = weight;
    //     }

    // int distance[Nodes];


    int adjMatrix[Nodes][Nodes] = { { 0, 4, 4, 0, 0, 0},
                                    { 4, 0, 2, 0, 0, 0},
                                    { 0, 0, 0, 3, 1, 6},
                                    { 0, 0, 0, 3, 0, 2},
                                    { 0, 0, 1, 0, 0, 3},
                                    { 0, 0, 0, 2, 3, 0}};
 

    // Dijkstras(adjMatrix, 0);
    bfs(adjMatrix, 0);

    
    
}