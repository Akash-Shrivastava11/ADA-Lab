#include <bits/stdc++.h>
#include<vector>
#include<time.h>
#include<unistd.h>
using namespace std;

int arr[1000],n;
void SelectionSort()
{
   for(int i=0;i<100;i++)
    usleep(1000);
    for(int i=0;i<n;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min_index])
                min_index=j;
        swap(arr[min_index],arr[i]);        
    }
}

int main()
{
    clock_t c1,c2;
    while(1){
    int x;
    cout<<"Enter the value of N: ";
    cin>>n;
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    // cout<<"Entered elements are: "<<endl;
    // for(int i=0;i<1000;i++)
    // cout<<arr[i]<<" ";
    // cout<<"\n";
    
    c1=clock();
    SelectionSort();
    c2=clock();
    cout<<"Time elapsed:"<<(double(c2-c1)/double(CLK_TCK))<<endl;
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    }
}