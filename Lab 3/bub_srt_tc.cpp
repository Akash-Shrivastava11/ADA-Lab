#include <bits/stdc++.h>
#include<vector>
#include<unistd.h>
#include <time.h>

using namespace std;

int arr[1000];
void BubbleSort(int n)
{
    for(int i=0;i<n;i++)
    usleep(1000);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i-1);j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
    }
}

int main()
{
    int x,n;
    // cout<<"Enter the integers(Press alphabet to end the input): "<<endl;
    clock_t c1,c2;
    while(1)
    {
    cout<<"Enter the number of elements: ";
    cin>>n;
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    // cout<<"Entered elements are: "<<endl;
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
    // cout<<"\n";

    c1=clock();
    cout<<c1<<"\n";
    BubbleSort(n);
    c2=clock();
    cout<<c2<<"\n";
    cout<<"Time Elapsed: "<<(double(c2-c1)/double(CLK_TCK))<<endl;
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
    }
}