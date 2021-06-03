#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int partition(int arr[], int l, int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        usleep(1);
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
void qs(int arr[], int l,int h){
    if(l<h){
        int pi=partition(arr,l,h);
        qs(arr,l,pi-1);
        qs(arr,pi+1,h);
    }
}
int main(){
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
    qs(arr,0,n-1);
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
    qs(arr,0,n-1);
    c2=clock();
    cout<<"Time elapsed for N = "<<n<<" "<<(float(c2-c1)/float(CLK_TCK))<<endl;
    n+=50;
    }
    }
}