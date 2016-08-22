#include "Graph.h"

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stack)
{
    visited[v] = true;
    
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visited[*i])
            topologicalSortUtil(*i, visited, stack);
    
    stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> stack;
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
        
    for(int i = 0; i < V; i++)
        if(!visited[i])
            topologicalSortUtil(i, visited, stack);
    
    while(!stack.empty()){
        
        cout << stack.top() << " ";
        stack.pop();
    }
}
int main()
{
   // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
}