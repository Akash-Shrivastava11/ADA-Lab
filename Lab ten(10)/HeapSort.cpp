#include <iostream> 
#include <bits/stdc++.h>
#include<unistd.h>
#include <time.h>
using namespace std; 

int arr[1000];
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void buildheap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
}
void heapSort(int arr[], int n) 
{  
	buildheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
 
int main() 
{ 
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
    heapSort(arr,n);
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
    heapSort(arr,n);
    c2=clock();
    cout<<"Time elapsed for N = "<<n<<" "<<(float(c2-c1)/float(CLK_TCK))<<endl;
    n+=50;
    }
    }
} 