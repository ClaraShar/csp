#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

long long n,m;//n个点，m条边 
long long graph_big[505][505],graph_small[505][505];
long long dis_big[505],dis_small[505];
long long path[505];//记录顶点v之前正在连续的小路
int vis_big[505],vis_small[505];

const int INF=0x3f3f3f3f;
const int NINF=0xc0c0c0c0;

void Init ()
{
	for (long long i=1;i<=n;i++)
	{
        for (long long j=1;j<=i;j++)
        {
            graph_big[i][j]=graph_big[j][i]=INF;
            graph_small[i][j]=graph_small[j][i]=INF;
        }
    }
    memset(vis_big,0,sizeof(vis_big));
    memset(vis_small,0,sizeof(vis_small));
}
 
void Getmap()
{
	long long t,a,b,c;
    for(int i=1;i<=m;i++)
	{
	  	cin>>t>>a>>b>>c;
	  	if(t==1)
	  		graph_small[a][b]=graph_small[b][a]=min(c,graph_small[a][b]);
		else
			graph_big[a][b]=graph_big[b][a]=min(c,graph_big[a][b]);
	}	
	
}
 
long long Dijkstra(long long v0)
{
	
	for(long long i=1;i<=n;i++)
	{
		dis_big[i]=graph_big[v0][i];
		dis_small[i]=graph_small[v0][i];//赋值源点到其他顶点的初始距离
		if(dis_small[i]<INF)
		{
            path[i]=dis_small[i];
            dis_small[i]*=dis_small[i];
        }
        else
        	path[i]=INF;
	}
	vis_big[v0]=1;
	vis_small[v0]=1;
	while(1)
	{
        long long minn=INF,flag=0,v=-1;
        for(long long j=1;j<=n;j++)
        {
			if(!vis_big[j]&&dis_big[j]<minn)
			{
	            flag=0;
	            v=j;
	            minn = dis_big[j];
	        }
	        if(!vis_small[j]&&dis_small[j]<minn)
	        {
	            flag=1;//用于区分大路or小路
                v=j;
                minn=dis_small[j];
            }
        }//循环找到当前初始距离最小的点temp
        if(v==-1)
        	break;//和n-1次更新差不多
        if(flag)
        	vis_small[v]=1;
	    else
	    	vis_big[v]=1;
	    for(long long j=1;j<=n;j++)
	    {
	        if(!vis_small[j] && graph_small[v][j]<INF)
	        {
	            if(flag)
	            {//prev到v之间是small road
	                long long temp=dis_small[v]-path[v]*path[v]+(path[v]+graph_small[v][j])*(path[v]+graph_small[v][j]);
	                if(dis_small[j]>temp || (dis_small[j]==temp && path[j]>path[v]+graph_small[v][j]))
	                {
	                    dis_small[j]=temp;
	                    path[j]=path[v]+graph_small[v][j];
		            }
		        }//对temp进行松弛
	            else
	            {//prev到v之间是big road
	                long long temp=dis_big[v]+graph_small[v][j]*graph_small[v][j];
	                if(dis_small[j]>temp || (dis_small[j]==temp && path[j]>graph_small[v][j]))
	                {
	                    dis_small[j]=temp;
	                    path[j]=graph_small[v][j];
                  	}
	            }
	        }
	        if(!vis_big[j] && graph_big[v][j]<INF)
	        {
	            if(flag)
	            {
                    long long temp=dis_small[v]+graph_big[v][j];
                    dis_big[j] = min(temp, dis_big[j]);
                }
                else
                {
                    long long temp=dis_big[v]+graph_big[v][j];
                    dis_big[j] = min(temp, dis_big[j]);
                }
            }
        }
    }
    return min(dis_big[n],dis_small[n]);
}
 
int main()
{
	cin>>n>>m;
	Init();
	Getmap();
	cout<<Dijkstra(1);
	return 0;
}
