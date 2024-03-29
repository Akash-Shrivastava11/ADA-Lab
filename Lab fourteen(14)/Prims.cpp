#include <bits/stdc++.h> 
using namespace std; 
#define V 4
int primMST(int graph[V][V]) 
{ 

	int key[V];int res=0; 
	fill(key,key+V,INT_MAX);
	bool mSet[V]={false}; key[0]=0;

	for (int count = 0; count < V ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
		        u=i;
		mSet[u] = true; 
		res+=key[u];

		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && mSet[v] == false) 
				key[v] = min(key[v],graph[u][v]); 
	} 
    return res;
} 

int main() 
{ 
    
	int graph[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin>>graph[i][j];
        }
        
    }
     

	cout<<primMST(graph); 

	return 0; 
} 