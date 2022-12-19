#include <iostream>

using namespace std;
#include <bits/stdc++.h>

const int Nodes = 6;

void bfs(int adjMatrix[Nodes][Nodes], int sourceNode){

    queue<int> queue;
    bool visited[Nodes];

    // Debugged code & found that not setting visited array to false makes it buggy.
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
        cout << output << " ";

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

void dfs(int adjMatrix[Nodes][Nodes], int sourceNode){

    stack<int> stack;
    bool visited[Nodes];

    for (int i = 0; i < Nodes; i++)
    {
        visited[i] = false;
    }

    visited[sourceNode] = true;

    stack.push(sourceNode);

    while(!stack.empty()){
        
        int output = stack.top();
        stack.pop();
        cout << output << " ";

        for (int i = 0; i < Nodes; i++)
        {
            if(adjMatrix[output][i] != 0 && visited[i] == false){
                visited[i] = true;
                stack.push(i);
            }
        }
        
    }
    
}

void dfsRecursive(int adjMatrix[Nodes][Nodes], int sourceNode){

    cout << sourceNode <<" ";

    bool visited[Nodes];

    // for (int i = 0; i < Nodes; i++)
    // {
    //     visited[i] = false;
    // }

    visited[sourceNode] = true;

    for (int i = 0; i < Nodes; i++)
    {
        if(adjMatrix[sourceNode][i] != 0 && visited[i] == false){
            dfsRecursive(adjMatrix, i);
        }
    }
    
}



int main(){


    int adjMatrix[Nodes][Nodes] = { { 0, 4, 4, 0, 0, 0},
                                    { 4, 0, 2, 0, 0, 0},
                                    { 0, 0, 0, 3, 1, 6},
                                    { 0, 0, 0, 3, 0, 2},
                                    { 0, 0, 1, 0, 0, 3},
                                    { 0, 0, 0, 2, 3, 0}};
 

    // Dijkstras(adjMatrix, 0);
    bfs(adjMatrix, 0);
    cout << endl;
    dfs(adjMatrix, 0);
    cout << endl;
    dfsRecursive(adjMatrix, 0);
    
}