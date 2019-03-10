#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,cnt=0;
	cin>>n;
	vector<int> a,b;
	for(int i=1;i<=n;++i)
	{
		int temp;
		cin>>temp;
		if(temp>0)
			a.push_back(temp);
		else
			b.push_back(temp*-1);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int>::iterator pa=a.begin();
	vector<int>::iterator pb=b.begin();
	while(pa!=a.end()&&pb!=b.end())
	{
		if(*pa==*pb)
		{
			cnt++;
			pa++;
			pb++;
		}
		else if(*pa>*pb)
			pb++;
		else if(*pa<*pb)
			pa++;
	}
	cout<<cnt;
	cin>>n;
	return 0;
}