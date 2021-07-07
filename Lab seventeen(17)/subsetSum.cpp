#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int counter, w[10], d, x[10];
void subset(int cs, int k, int r)
{
    
    x[k] = 1;  //kind of boolean or a check matrix
    if (cs + w[k] == d)
    {
        cout << "Subset solution "<<counter++<<": ";
        for (int i = 0; i <= k; i++)
        {
            if (x[i] == 1)
                cout << w[i]<<" ";
        }
        cout<<"\n";
    }
    else
    if (cs + w[k] + w[k + 1]<= d) // It's cutting down the recurssion
    //as on every point we keep checking the sum
    //therefore call is not made for every possible subset
        subset(cs + w[k], k + 1, r - w[k]);
    if ((cs + r - w[k] >=d) && (cs + w[k + 1]) <= d)
    {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);//case:w[k] is not included.
    }
}

int main()
{
    int sum = 0, i, n;
    cout<<"Enter the  number of elements: ";
    cin>>n;
    cout<<"Enter the elements in ascending order: ";
    for (i = 0; i<n; i++)
        cin>>w[i];
    cout<<"Enter the required sum: ";
   cin>>d;
    for (i = 0; i<n; i++)
        sum += w[i];
    if (sum<d)
    {
       cout<<"No solution exists";
       exit(0);
    }
 cout<<"The solution is:\n";
    counter = 0;
    subset(0, 0, sum);
}