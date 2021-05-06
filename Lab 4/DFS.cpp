#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void addEdge(vector<int>adj[],int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int>adj[],int v)
{
    cout<<"The neighbour vertices are: "<<"\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<": ";
        for(auto x:adj[i])
        cout<<x<<" ";
        cout<<"\n";
    }
}
void DFS_Rec(vector<int>adj[],int s, bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        DFS_Rec(adj,u,visited);
    }
}

void DFS(vector<int>adj[],int v,int s)
{
    bool visited[v];
    int flag=1;
    for(int i=0;i<v;i++)
    visited[i]=false;
    DFS_Rec(adj,s,visited);
    for(int i=0;i<v;i++)
    {
    if(visited[i]==false)
    flag=0;
    }
    if(flag==0)
    cout<<"\nGraph is disconnectd";
    else if(flag==1)
    cout<<"\nGraph is connected";
}



int main()
{
    int v,e,x,y,start;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>v;
    cout<<"\n";
    vector<int>adj[v];
    cout<<"Enter the number of edges: ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the vertices pair for edge "<<i+1<<": ";
        cin>>x>>y;
        addEdge(adj,x,y);
    }
    printGraph(adj,v);
    cout<<"\n";
    cout<<"Enter the start point for traversal of graph: ";
    cin>>start;
    DFS(adj,v,start);
}