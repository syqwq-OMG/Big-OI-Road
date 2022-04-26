#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int nxt;
    int to;
    int val;
};

struct node{
    int ver;
    int dis;
    bool operator <(const node& x) const{
        return dis>x.dis;   // 小根堆
    }
};

const int N=1e6+5;
const int M=2e6+5;
const int p=1e5+3;
int n,m;
int head[N];
Edge edge[M];
int tot=0;

priority_queue<node> pq;
int d[N];   // 最短路长度
bitset<N> vis;  // 是否更新过
int ans[N];

void add(int x,int y,int z){
    edge[++tot].to=y;
    edge[tot].val=z;
    edge[tot].nxt=head[x];
    head[x]=tot;
}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>m;
    for(re int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        add(u,v,1);
        add(v,u,1); // 默认边权为 1
    }

    memset(d,0x3f,sizeof(d));
    // 二叉堆优化 Dijkstra
    d[1]=0; ans[1]=1; pq.push((node){1,0});
    while(!pq.empty()){
        int x=pq.top().ver; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;

        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            int w=edge[i].val;
            if(d[x]+w<d[y]){
                d[y]=d[x]+w;
                ans[y]=ans[x];  // 第一次更新这个长度路径
                pq.push((node){y,d[y]});
            }else if(d[x]+1==d[y]){
                ans[y]=(ans[y]+ans[x])%p;   // 再次更新这个长度的路径, 那就原基础上相加
            }
        }
    }

    // for(re int i=1;i<=n;i++){   //! 枚举顶点
    //     for(re int j=head[i]; j; j=edge[j].nxt){   // 枚举通向的顶点
    //         int x=edge[j].to;
    //         if(d[x]==d[i]+1) ans[x]=(ans[x]+ans[i])%p;  // 在最短路径中, 若 i 就是在 x 前面, 说明这就是一条路径
    //     }
    // }

    for(re int i=1;i<=n;i++) cout<<ans[i]<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
