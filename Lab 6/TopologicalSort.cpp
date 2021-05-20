#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int v)
{
    cout << "The neighbour vertices are: "
         << "\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
   
}

void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
    for(int i=0;i<V;i++)
    {
        cout<<"In-Degree of vertex "<<i<<":"<<in_degree[i]<<endl;
    }
    cout<<"\n";
    
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        cout<<u<<" "; 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
    } 
}

    int main()
    {
        int V, e, x, y, start;
        cout << "Enter the number of vertices in the graph: ";
        cin >> V;
        cout << "\n";
        vector<int> adj[V];
        cout << "Enter the number of edges: ";
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter the vertices pair for edge " << i + 1 << ": ";
            cin >> x >> y;
            addEdge(adj, x, y);
        }
        printGraph(adj, V);
        cout << "\n";
        topologicalSort(adj, V);
    }
