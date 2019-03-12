#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	int num;
	int cnt;
	Node(int n, int c) : num(n), cnt(c) {}//这是一个构造函数
};

bool cmp(Node a,Node b)
{
	if(a.cnt==b.cnt)
		return a.num<b.num;
	return a.cnt>b.cnt;
}

int main()
{
	int n;
	cin>>n;
	map<int,int> m;
	for(int i=0;i<n;++i)
	{
		int temp;
        cin>>temp;
        m[temp]++;
	}
	map<int,int>::iterator it=m.begin();
	vector<Node> a;
	for(;it!=m.end();++it)
		a.push_back(Node(it->first,it->second));
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();++i)
		cout<<a[i].num<<" "<<a[i].cnt<<endl;
	cin>>n;
}