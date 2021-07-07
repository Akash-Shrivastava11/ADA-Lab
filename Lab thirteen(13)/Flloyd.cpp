#include <bits/stdc++.h>
using namespace std;
int a[10][10], n;
void floyds()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j<= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    cout << "All pair shortest path is:"
         << "\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << a[i][j]<<" ";
        }
        printf("\n");
    }
}

int main()
{
    int i, j;
    cout<<"Enter the number of vertices";
    cin>>n;
    cout<<"Enter the cost matrix";
    for (i = 1; i<=n; i++)
    {
        for (j = 1; j<= n; j++)
        {
            cin>>a[i][j];
        }
    }
    floyds();
}