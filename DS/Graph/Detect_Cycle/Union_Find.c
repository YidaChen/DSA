#include <stdio.h>
#include <stdbool.h>

typedef struct Edge
{
    int src, dest;
} Edge;

typedef struct Graph
{
    int V, E;
    Edge *edge;
} Graph;

Graph* new_Graph(int V, int E)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    
    graph->edge = malloc(sizeof(Edge) * E);
    return graph;
}
int find(int parent[], int i)
{
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y)
{
    int xSet = find(parent, x);
    int ySet = find(parent, y);
    parent[xSet] = ySet;
}
bool isCycle(Graph *graph)
{
    int *parent = malloc(sizeof(int) * graph->V);
    memset(parent, -1, sizeof(int) * graph->V);
    
    for(int i = 0; i < graph->E; i++)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
        
        if(x == y)
            return true;
            
        Union(parent, x, y);
    }
    return false;
}

int main()
{
    int V = 3, E = 3;
    struct Graph* graph = new_Graph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
}