#include <iostream>
#include <vector>
using namespace std;

vector<int> output;
vector<int> a;
int main()
{
	int n,m;
	cin>>n>>m;
	a.push_back(0);
	for(int i=1;i<=n;++i)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=1;i<=m;++i)
	{
		int opt;
		cin>>opt;
		if(opt==1)
		{
			int l,r,v;
			cin>>l>>r>>v;
			if(l==r)
			{
				if(a[l]%v==0)
					a[l]/=v;
				continue;
			}
			int p=l,q=r;
			while(p<q)
			{
				if(a[p]%v==0)
					a[p]/=v;
				if(a[q]%v==0)
					a[q]/=v;
				p++;
				q--;
			}
			if(p==q&&a[p]%v==0)
				a[p]/=v;
		}
		else if(opt==2)
		{
			int l,r,sum=0;
			cin>>l>>r;
			if(l==r)
			{
				sum+=a[l];
				output.push_back(sum);
				continue;
			}
			int p=l,q=r;
			while(p<q)
			{
				sum+=a[p]+a[q];
				p++;
				q--;
			}
			if(p==q)
				sum+=a[p];	
			output.push_back(sum);
		}
	}
	for(int i=0;i<output.size();++i)
		cout<<output[i]<<endl;
	return 0;
}
/*
https://blog.csdn.net/nininicrystal/article/details/78657052?utm_source=blogxgwz5
https://blog.csdn.net/nininicrystal/article/details/78656755
*/