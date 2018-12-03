#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector<int> students;
	for(int i=1;i<=n;++i)
		students.push_back(i);
	for(int i=0;i<m;++i)
	{
		int p,q;
		cin>>p>>q;
		vector<int>::iterator pos=find(students.begin(),students.end(),p);
		students.erase(pos);
		students.insert(pos+q,p);
	}
	for(int i=0;i<students.size()-1;++i)
		cout<<students[i]<<" ";
	cout<<students[n-1];
	return 0;
}