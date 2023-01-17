
#include <bits/stdc++.h>
using namespace std;


const int V = 6;


int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}


void primMST(int graph[V][V])
{

	int parent[V];

	int key[V];

	bool mstSet[V];

	int dist[V];

	for (int i = 0; i < V; i++){
		key[i] = INT_MAX, mstSet[i] = false;

    }
	key[0] = 0;
	parent[0] = -1; 
    dist[0] = 0;

	for (int count = 0; count < V; count++) {
		
		int u = minKey(key, mstSet);
		
		mstSet[u] = true;
    
		for (int v = 0; v < V; v++){

			if (graph[u][v] && mstSet[v] == false
				 && dist[u] != INT_MAX ){                       //  graph[u][v] < key[v] 
                    // parent[v] = u, key[v] = graph[u][v];

                    int tempDistance = dist[u] + graph[u][v];

                    if (tempDistance < dist[v]){
                        dist[v] = tempDistance;
                    }

                }
        }	

	}

      for (int i = 0; i < V; i++)
        {
            cout << dist[i] << " ";
        }
        

	// printMST(parent, graph);


}


int main()
{
	
    int graph[V][V] = { { 0, 4, 4, 0, 0, 0},
                        { 4, 0, 2, 0, 0, 0},
                        { 0, 0, 0, 3, 1, 6},
                        { 0, 0, 0, 3, 0, 2},
                        { 0, 0, 1, 0, 0, 3},
                        { 0, 0, 0, 2, 3, 0}};

	primMST(graph);

	return 0;
}

