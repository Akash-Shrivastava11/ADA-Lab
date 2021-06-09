#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <unistd.h>
#include <time.h>
using namespace std;

void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void mergeSort(int arr[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
	
     int x;
    cout<<"Enter 1 to enter elements manually, 2 to check for random elements"<<endl;
    cin>>x;
    if(x==1){
        int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;    
    int arr[n];
    cout<<"Enter array elements"<<endl;
    for(int &i:arr)
    cin>>i;
    clock_t c1,c2;
    c1=clock();
    for(int i=0;i<100;i++)
    {usleep(10);}
    mergeSort(arr,0,n-1);
    c2=clock();
    cout<<"Time elapsed for N = "<<n<<" "<<(float(c2-c1)/float(CLK_TCK))<<endl;
    cout<<"Array after sorting:"<<endl;
    for(int i:arr)
    cout<<i<<" ";
    cout<<endl;
    }
    
    else{
    int n=50;
    while(n<=500){
        int arr[n];
    for(int &i:arr)
    i= rand() % INT_MAX;
    clock_t c1,c2;
    c1=clock();
    for(int i=0;i<100;i++)
    {usleep(10);}
    mergeSort(arr,0,n-1);
    c2=clock();
    cout<<"Time elapsed for N = "<<n<<" "<<(float(c2-c1)/float(CLK_TCK))<<endl;
    n+=50;
    }
    }
}
