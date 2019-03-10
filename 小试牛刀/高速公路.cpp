#include <iostream>
#include <vector>
using namespace std;

int n,m;
int map[1005][1005];
vector<int> path[1005];//每个点跟着一串不定数量的相连点 

void DFS(int a,int visit[],int b)//已知有向路径a->b 
{
    visit[a]=1;
    map[a][b]=1;
    for(int i=0;i<path[a].size();i++)//遍历所有与a相连的未被访问过的点 
        if(visit[path[a][i]]==0)//如果未被访问，DFS访问，建立连通性
	        DFS(path[a][i],visit,b);
}

int main()
{
	cin>>n>>m;
	int i,j,cnt=0;
	for(i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		path[a].push_back(b);
	}
	for(i=1;i<=n;i++)
	{
		//每个点的访问visit都要初始化
        int visit[1005]={0};//每个点开始的遍历都要扩展到整张图,填图时记录是否访问过某点 
	    DFS(i,visit,i);//到自身存在有向路径，作为起始状态 
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
            if(map[i][j]==1&&map[j][i]==1)//i与j互通  
            	cnt++; 
    }
    cout<<cnt<<endl;
    cin>>n;
	return 0;
}