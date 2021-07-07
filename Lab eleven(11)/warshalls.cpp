#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
int n, a[10][10], p[10][10];
void warshall(int n, int a[10][10], int p[10][10])
{
    int i, j, k;
    for (i = 1 ; i<=n ;i++)
        for (j =1 ; j<=n ; j++)
            p[i][j] = a[i][j];
    for (k = 0; k<=n ; k++)
        for (i = 0;i<=n;i++)
            for (j = 0; j<=n ; j++)
                if ((p[i][j] == 0) && (p[i][k] == 1 && p[k][j] == 1))
                    p[i][j] = 1;
}
int main()
{
    int i, j;
    cout<<"Enter the number of vertices";
    cin>>n;
    cout<<"Enter the adjecency matrix";
    cout<<"\n";
    for (i = 1; i<=n; i++)
    {
        for (j = 1; j<=n ;j++)
        {
            cin>>a[i][j];
        }
    }
    warshall(n, a, p);
    cout<<"Transitive closure"<<"\n";
    for (i = 1 ; i<=n; i++)
    {
        for (j = 1;j<=n;j++)
        {
           cout<<p[i][j];
        }
        printf("\n");
    }
    
}