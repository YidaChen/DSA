#include <stdio.h>
#include <stdbool.h>

typedef struct Edge
{
    int src, dest, weight;
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
int compar(const void* a, const void* b)
{
    return ((Edge*)a)->weight > ((Edge*)b)->weight;
}
void KruskalMST(Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    
    Edge result[V-1];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compar);
    
    Subset *subset = malloc(sizeof(Subset) * V);
    
    for(int v = 0; v < V; v++)
    {
        subset[v].parent = v;
        subset[v].rank = 0;
    }
    
    while(e < V - 1)
    {
        Edge nextEdge = graph->edge[i++];
        
        int x = find(subset, nextEdge.src);
        int y = find(subset, nextEdge.dest);
        
        if(x != y)
        {
            result[e++] = nextEdge;
            Union(subset, x, y);
        }
    }
    
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main()
{
    /* create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph *graph = new_Graph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
}