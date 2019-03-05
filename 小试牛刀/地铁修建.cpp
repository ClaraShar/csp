//最小生成树——Kruskal，第二次见面啦～

//要注意数组范围
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n,m,root,f[100005];//顶点的权值、判断连通性
struct edge{
	int x,y,d;//x、y、权值
}e[200010];

bool cmp(edge e1,edge e2)
{
	return e1.d<e2.d;
}

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);//路径优化
}

int Kruskal()
{
	int res=-1,cnt=0;//res要赋初值为-1，因为时间没有负数，后面要作max比较
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int xx=find(e[i].x);
		int yy=find(e[i].y);
		if(xx!=yy)//掌门不同？踢馆！~
			f[xx]=yy;//合并boss
		if(find(1)==find(n))//掌门一样，就连通了，当前即为最小
		{
			res=e[i].d;
			break;
		}
	}
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].x>>e[i].y>>e[i].d;
	}
	f[0]=0;//掌门编号，必不可少
	for(int i=1;i<=n;i++)
		f[i]=i;
	cout<<Kruskal();
	cin>>n;
	return 0;
}
