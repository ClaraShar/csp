#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n,k,counter=1;
	queue<int> child;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		child.push(i);//用于保存小孩的序号
	while(child.size()>1)
	{
		int top=child.front();
		child.pop();
		if(counter%k!=0&&counter%10!=k)
			child.push(top);
		counter++;
	}
	cout<<child.front();
	return 0;
}