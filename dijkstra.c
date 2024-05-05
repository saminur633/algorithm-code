#include <limits.h>

#include <stdbool.h>

#include <stdio.h>

#define V 5

int minKey(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){

        if (sptSet[v] == 0 && dist[v] < min){

            min = dist[v]; min_index = v;
	 }	

     }

    return min_index;

}

int printSPT(int dist[])
{
    int sum = 0;

    printf("Vertex \tDistance from the Source Node\n");
    for (int i = 0; i < V; i++){
        printf("%d - \t%d \n", i, dist[i]);
    }
}
void dijkstra(int graph[V][V], int src)
{

   int dist[V];

   int sptSet[V];

   for (int i = 0; i < V; i++){
       dist[i] = INT_MAX; 
	sptSet[i] = 0;
   }

    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {

        int u = minKey(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
           if (sptSet[v] == 0 && graph[u][v] != 0 && dist[u] != INT_MAX &&  dist[u] + graph[u][v] < dist[v])
		{dist[v] = dist[u] + graph[u][v];}

    }
    printSPT(dist);

}


int main(){
    int graph[V][V] = {{5,3, 3, 0, 1, 5},
                       {5, 3, 2, 0, 1 ,3},
                       {3, 3, 2, 0, 1, 3},
                       {3, 3, 2, 0, 1, 3},
                       {3, 3, 2, 0, 1, 3},
                       {3, 3, 2, 0, 1, 3}};
    dijkstra(graph, 3);
    return 0;
}