#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	map<int,int> m;
	if(n>0&&n<=1000)
    {
		for(int i=0;i<n;++i)
		{
			int temp;
			cin>>temp;
			m[temp]++;
		}
		map<int,int>::iterator it=m.begin();
	    int max=it->first;
		for(;it!=m.end();it++)
		{
			if(it->second>m[max])
				max=it->first;
			else if(it->second==m[max]&&it->first<max)
				max=it->first;
		}
		cout<<max;
	}
	return 0;
}
