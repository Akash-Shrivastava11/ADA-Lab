#include<iostream>
#include<time.h>
#include<unistd.h>
int arr[1000],n;
using namespace std;
void insSrt()
{
    for(int i=1;i<n;i++)
    {
          usleep(1000);
        int key=arr[i];
        int j=i-1;
        while(j>=0 &&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    
    c1=clock();
    insSrt();
    c2=clock();
    cout<<"Time elapsed:"<<(double(c2-c1)/double(CLK_TCK))<<endl;
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
    }
}