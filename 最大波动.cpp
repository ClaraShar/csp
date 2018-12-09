#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,max=INT_MIN;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		if(abs(a[i+1]-a[i])>max)
			max=abs(a[i+1]-a[i]);
	}
	cout<<max;
	return 0;
}