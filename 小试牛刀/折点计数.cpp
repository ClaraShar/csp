#include <iostream>
using namespace std;

int a[1005];
int main()
{
	int n,res=0;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=1;i<n-1;++i)
	{
		if((a[i-1]>a[i]&&a[i+1]>a[i])||(a[i-1]<a[i]&&a[i+1]<a[i]))
			res++;
	}
	cout<<res;
	return 0;
}