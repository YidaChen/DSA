#include <stdio.h>
#include <stdbool.h>

typedef struct Edge
{
    int src, dest;
} Edge;
typedef struct Subset
{
    int parent, rank;
} Subset;
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
int find(Subset subset[], int i)
{
    if(subset[i].parent != i)
        subset[i].parent = find(subset, subset[i].parent);
    return subset[i].parent;
}
void Union(Subset subset[], int x, int y)
{
    int xRoot = find(subset, x);
    int yRoot = find(subset, y);
    
    if(subset[xRoot].rank < subset[yRoot].rank)
        subset[xRoot].parent = yRoot;
        
    else if(subset[xRoot].rank > subset[yRoot].rank)
        subset[yRoot].parent = xRoot;
        
    else {
        subset[yRoot].parent = xRoot;
        subset[xRoot].rank++;
    }
}
bool isCycle(Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    
    Subset *subset = malloc(sizeof(Subset) * V);
    
    for(int v = 0; v < V; v++)
    {
        subset[v].parent = v;
        subset[v].rank = 0;
    }
    
    for(int e = 0; e < E; e++)
    {
        int x = find(subset, graph->edge[e].src);
        int y = find(subset, graph->edge[e].dest);
        
        if(x == y)
            return true;
            
        Union(subset, x, y);
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