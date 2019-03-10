#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n,m;//n个点，m条边 
int graph[10005][10005];
int dis[10005],vis[10005],cost[10005];

const int INF=0x3f3f3f3f;
 
void Dijkstra(int v0)
{
	for(int i=1;i<=n;i++)
       dis[i]=cost[i]=INF;
	dis[v0]=cost[v0]=0;
	vis[0]=1;
	while(1)
	{
        int minn=INF,v=-1;
        for(int j=1;j<=n;j++)
        {
			if(!vis[j]&&dis[j]<minn)
			{
	            v=j;
	            minn=dis[j];
	        }
        }//循环找到当前初始距离最小的点minn
        if(v==-1)
        	break;//和n-1次更新差不多
        vis[v]=1;
	    for(int j=1;j<=n;j++)
	    {
	        if(!vis[j] && graph[v][j]+dis[v]<dis[j])
	        {
                dis[j]=graph[v][j]+dis[v];
                cost[j]=graph[v][j];
            }
            if(!vis[j] && graph[v][j]+dis[v]==dis[j])
            	cost[j]=min(graph[v][j],cost[j]);
        }
    }
}
 
int main()
{
	cin>>n>>m;
	int a,b,c;
    for(int i=1;i<=m;i++)
	{
	  	cin>>a>>b>>c;
	  	graph[a][b]=graph[b][a]=c;
	}
	Dijkstra(1);
	int res=0;
	for(int i=2;i<=n;++i)
		res+=cost[i];
	cout<<res;
	cin>>n;
	return 0;
}
