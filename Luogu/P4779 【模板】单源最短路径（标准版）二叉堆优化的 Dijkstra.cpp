// 二叉堆优化的 Dijkstra
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;

// 链式向前星
struct Edge{
    int to;     // x->当前节点的节点编号
    int nxt;    // x->当前节点对应的数组索引
    int val;    // 边权
};

// 优先队列元素
struct node{
    int ver;    // 顶点编号
    ll dis;     // 到 s 的距离, 用于小根堆排序
    // 重载 < 运算符
    bool operator <(const node& x) const{
        return dis>x.dis;   // 小根堆 所以是 >
    }
};

const int N=1e5+5;
const int M=2e5+5;

int n,m,s;

// 存图
int head[N];
Edge edge[M];
int tot=0;

// 加边(起点, 终点, 边权)
void add(int x,int y,int w){
    edge[++tot].to=y;
    edge[tot].val=w;
    edge[tot].nxt=head[x];
    head[x]=tot;
}

bitset<N> vis;
// 优先队列内部实质是一个 小根堆
priority_queue<node> pq;
ll dis[N];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    memset(dis,0x3f,sizeof(dis));   // 初始化极大值
    cin>>n>>m>>s;
    for(re int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
    }

    // 算法主体
    dis[s]=0; pq.push((node){s,0}); // s 入堆
    while(!pq.empty()){ // 堆中还有可更新的元素
        int x=pq.top().ver;
        // int d=pq.top().dis; 不必取出, 仅用来给 priority_queue 排序
        pq.pop();
        // 标记蓝白点
        if(vis[x]) continue;
        vis[x]=1;
        // 与 x 相邻的可更新的点全部入堆...怎么感觉有点SPFA的意思在里面
        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            int w=edge[i].val;
            if(dis[x]+w<dis[y]){
                dis[y]=dis[x]+w;
                pq.push((node){y,dis[y]});  // 入堆
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
