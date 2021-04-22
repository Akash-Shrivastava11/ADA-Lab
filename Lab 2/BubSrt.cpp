#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> BSrt(vector<int>&v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i-1);j++)
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
    }
    return v;
}

int main()
{
    int x;
    vector<int>v;
    cout<<"Enter the integers(Press alphabet to end the input): "<<endl;
    while(cin>>x)
    {
        v.push_back(x);
    }
    int n=v.size();
    cout<<"Entered elements are: "<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    cout<<"\n";

    v=BSrt(v);
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}