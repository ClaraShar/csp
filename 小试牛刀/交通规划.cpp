#include <iostream>
#include <queue>
#include <vector>
#define NMAX 10005
using namespace std;

//用邻接表存储
//v表示节点，w表示出发点到v点的距离
struct Node {
    int v;
    int w;
    Node(int vv=0, int ww=0){
        v=vv,w=ww;
    }
    // 优先队列将按距离从小到大排列
    friend bool operator<(Node n1, Node n2) {
        return n1.w>n2.w;
    }
};

//v表示边的另一端节点，cost表示该边的权重
struct Edge {
    int v;
    int w;
    Edge(int vv=0, int ww=0) {
        v=vv,w=ww;
    }
};

vector<Edge>G[NMAX];//无向图
bool marked[NMAX];      // D算法中每个顶点仅处理一遍
int dist[NMAX];        // 出发点到某点距离
int cost[NMAX];        // 接通该点需要增加的边的权重
int n,m;

void Dijkstra(int s){
    for (int i=0;i<=n;i++){
        cost[i]=dist[i]=INT_MAX;
        marked[i]=false;
    }
    dist[s]=0;
    cost[s]=0;
    priority_queue<Node>pq;     // 保存<v,dist[v]>且按dist[v]升序排列
    pq.push(Node(s,0));
    marked[0]=true;

    Node tmp;
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        int v = tmp.v;
        if (!marked[v]) {
            marked[v]=true;
            int len = G[v].size();
            for (int i = 0; i < len; i++) {
                int vv = G[v][i].v;
                if(marked[vv])
                    continue;
                int ww=G[v][i].w;
                int newdist=dist[v]+ww;
                if (dist[vv]>newdist) {
                    dist[vv]=newdist;
                    cost[vv]=ww;   // 增加的内容
                    pq.push(Node(vv,dist[vv]));
                }
                // 增加的内容
                // 加入点vv时若出现多种距离相同的方案，选取新边最小那个
                if (dist[vv]==newdist)
                    cost[vv]=min(cost[vv],ww);
            }
        }
    }
}

int main()
{
	cin>>n>>m;
	int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }//无向图
    Dijkstra(1);
    // 统计边权重
    int res=0;
    for (int i=2;i<=n;i++)
        res+=cost[i];
    cout<<res<<endl;
	return 0;
}