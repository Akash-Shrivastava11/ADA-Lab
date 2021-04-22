#include<iostream>
using namespace std;

int  gcd(int a,int b)
{
    while (a!=b)
    {
        if(a>b)     
        a=a-b;
        else
        b=b-a;
    }
    return a;
    
}

int main()
{
    int a,b;
   cout<<"Enter the two numbers: "<<endl;
		cin>>a>>b;
		cout<<"H.C.F: "<<gcd(a,b);
}