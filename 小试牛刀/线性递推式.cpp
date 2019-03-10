#include <iostream>
#include <vector>
using namespace std;

int n_k;
int DFS(vector<int> k,vector<int> a,int pos)
{
	a[pos]=0;
	if(pos==0)
		return 1;
	for(int j=1;j<=min(n_k,pos);++j)
		a[pos]+=k[j]*DFS(k,a,pos-j);
	return a[pos];
}

int main()
{
	int l,r;
	cin>>n_k>>l>>r;
	vector<int> k,a;
	for(int i=0;i<=n_k;++i)
		k.push_back(0);
	for(int i=0;i<=r;++i)
		a.push_back(0);
	for(int i=1;i<=n_k;++i)
		cin>>k[i];
	for(int i=l;i<=r;++i)
	{
		for(int j=1;j<=min(n_k,i);++j)
			a[i]+=k[j]*DFS(k,a,i-j);
	}
	for(int i=l;i<=r;++i)
		cout<<a[i]<<endl;
	cin>>n_k;
	return 0;
}