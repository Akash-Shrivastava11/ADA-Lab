#include<iostream>
using namespace std;

int bSearch(int arr[],int low,int high,int x)
{
    if(low>high) 
    return -1;
    int mid=(low+high)/2;

    if(x>arr[mid])
    bSearch(arr,mid+1,high,x);

    else if (x<arr[mid])
    bSearch(arr,low,mid-1,x);

    else 
    return (mid+1);

}
int main()
{
    int n,arr[100],ele;
    cout<<"Enter the number of elements in array";
    cin>>n;
    cout<<"Enter the elements";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int low=arr[0];
    int high = arr[n-1];
    cout<<"Enter the search element in the array";
    cin>>ele;
    cout<<"Element is present at"<<bSearch(arr,low,high,ele)<<"position";
}