#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    
    int V; //No. of vertices
    list<int> *adj; //list's array
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
        //adj = (list<int>*)malloc(sizeof(list<int>) * V); not work?
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w);
        //adj[w].push_back(v); //undirected
    }
    //only the vertices reachable from a given source vertex.
    void BFS(int v){ //Starting vertex
        
        bool *visited = new bool[V];
        //bool *visited = (bool*)malloc(sizeof(bool) * V);
        for(int i = 0; i < V; i++)
            visited[i] = false;
        
        queue<int> q;
        
        visited[v] = true;
        q.push(v);
        
        list<int>::iterator w;
        while(!q.empty()){
            
            v = q.front();
            q.pop();
            printf("%d ", v);
            
            for(w = adj[v].begin(); w != adj[v].end(); ++w){
                
                if(!visited[*w]){
                    visited[*w] = true;
                    q.push(*w);
                }
            }
        }
    }
    
    void DFSUtil(int v, bool visited[]){
        
        visited[v] = true;
        printf("%d ", v);
        
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
            if(!visited[*i])
                DFSUtil(*i, visited);
    }
    
    void DFS(int v){
        
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
            
        //DFSUtil(v, visited);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFSUtil(i, visited);
    }
    
    void print(){
        
        list<int>::iterator i;
        for(int v = 0; v < V; v++){
            
            printf("\n Adjacency list of vertex %d\n head ", v);
            for(i = adj[v].begin(); i != adj[v].end(); ++i){
                
                printf("-> %d", *i);
            }
            printf("\n");
        }
    }
    
    void topologicalSortUtil(int v, bool visited[], stack<int> &stack);
    
    void topologicalSort();
};