/*树的直径，即在树中找出两个结点，使得这两个结点间的距离最长，这个最长距离称为直径。
定理：假设路径s-t为树的直径，则从任意一点u出发找到的最远的点一定是s、t中的一点。
做法：两次BFS求解，第一次任选一个点，求该点能到达的最远点u，第二次从u出发，求u能到达的最远点v，则u，v的距离是树的直径。
*/

//其实是图
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 20000 + 5;
vector<int> G[maxn];//变长数组
bool vis[maxn];
int n, m, ans = 0, depth[maxn];

int main()
{
    cin >> n >> m;
    for (int u = 2, v; u <= n + m; ++u) {
        cin >> v;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    int now;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = 0; i < G[now].size(); ++i)//G[now]为点now所邻接的所有点的数组集合
        {
            int v = G[now][i];
            if(vis[v])
            	continue;
            vis[v] = true;
            Q.push(v);
        }
    }
    //now为从1开始找到的与之最远的一点
    Q.push(now);
    memset(vis, false, sizeof(vis));
    vis[now] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = 0; i < G[now].size(); ++i)
        {
            int v = G[now][i];
            if (vis[v])
            	continue;
            vis[v] = true;
            depth[v] = depth[now] + 1;//每遍历到一个点，花费时间加1
            Q.push(v);
        }
    }
    //此时的now为从之前的now开始找到的与之最远的一点
    cout<<depth[now];//新的now
    return 0;
}