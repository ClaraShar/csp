#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k,cnt=0,weight=0;
	vector<int> people;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		weight+=a[i];
		if(weight>=k)
		{
			people.push_back(weight);
			weight=0;
		}
		else
		{
			if(i==n-1)
				people.push_back(weight);
		}
	}
	cout<<people.size();
	return 0;
}