//转自https://blog.csdn.net/lbperfect123/article/details/84281300

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define Inf 0x3f3f3f3f
 
using namespace std;
 
int map[1005][1005];//存储图的数据结构，邻接矩阵
int vis[1005],dis[1005];//vis数组用来表示该点是否已经找到最小值，1是0否；dis数组存储1号顶点到其余各个顶点的初始路程
int n,m;//n个点，m条边
 
void Init ()
{
	memset(map,Inf,sizeof(map));//不连通的点距离为∞
	for(int i=1;i<=n;i++)
		map[i][i]=0;//自己到自己距离为0
}
 
void Getmap()
{
	int u,v,w;
    for(int t=1;t<=m;t++)
	{
	  	scanf("%d%d%d",&u,&v,&w);
	  	if(map[u][v]>w)
		{
			map[u][v]=w;
		    map[v][u]=w;
	    }
	}
}
 
void Dijkstra(int u)
{
	memset(vis,0,sizeof(vis));
	for(int t=1;t<=n;t++)
	{
		dis[t]=map[u][t];//赋值源点到其他顶点的初始距离
	}
	vis[u]=1;
	for(int t=1;t<n;t++)
	{
		int minn=Inf,temp;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dis[i]<minn)
			{
				minn=dis[i];
				temp=i;
			}
		}//循环找到当前初始距离最小的点temp
		vis[temp]=1;
		for(int i=1;i<=n;i++)
		{
			if(map[temp][i]+dis[temp]<dis[i])
				dis[i]=map[temp][i]+dis[temp];
		}//对temp进行松弛
	}//n-1次松弛
}
 
int main()
{
	scanf("%d%d",&m,&n);
	Init();//对图的初始化
	Getmap();
	Dijkstra(n);
	printf("%d\n",dis[1]);	
	return 0;
}
