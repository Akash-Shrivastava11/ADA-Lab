#include <iostream>
#include <limits.h>
using namespace std;
 int gcd(int a, int b)
{
	if(b==0)
	return a;
	return gcd(b, a % b);
}

int main() {
	int a ,b;
    	cout<<"Enter the two numbers: "<<endl;
		cin>>a>>b;
		cout<<"H.C.F: "<<gcd(a,b);
}