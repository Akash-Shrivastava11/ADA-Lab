#include<bits/stdc++.h>
using namespace std;
int c[10][10],n;
void kruskals()
{
    int u, v, a, b, min;
    int ne = 0, mincost = 0;  //ne==no of edges in MST
    int parent[10];
    for (int i = 1; i <=n; i++)
    {
        parent[i] = 0;
    }
    while (ne != n - 1)
    {
        min = 9999;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        while (parent[u] != 0)
        {
            u = parent[u]; 
        }
        while (parent[v] != 0)
        {
            v = parent[v];
        }
        if (u != v)//not bel to same set , no cycle
        {
            cout << a << " " << b << " " << min<<"\n";
            parent[v] = u;
            ne = ne + 1;
            mincost = mincost + min;
        }
        c[a][b] = c[b][a] = 9999;
    }
    cout <<"Min cost is: "<< mincost;
}

int main()
    {
        cout<<"Enter the number of vertices: ";
        cin>>n;
        cout<<"Enter the cost matrix: ";
        for (int i = 1; i<= n; i++)
        {
            for (int j = 1; j<= n; j++)
            {
                cin>>c[i][j];
            }
        }
        kruskals();
    }