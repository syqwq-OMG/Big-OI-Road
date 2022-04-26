// Prim
#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int to,nxt,val;
};

const int M=2e5+5;
const int N=5e3+5;
int n,m;
int tot=0;
int head[N];
Edge edge[M<<1];    // 无向图开两倍

int dis[N]; // 未更新的点到已更新点的最短距离
int mst=0;
bitset<N> vis;  // 是否更新

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
    memset(dis,0x3f,sizeof(dis));
    cin>>n>>m;
    for(re int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dis[1]=0;
    for(re int i=1;i<=n;i++){
        int node=0;
        for(re int j=1;j<=n;j++)
            if((!vis[j]) && dis[j]<dis[node]) node=j;   // 寻找离更新过的点最近的点
        vis[node]=1;
        for(re int j=head[node]; j; j=edge[j].nxt){
            int y=edge[j].to; int w=edge[j].val;
            if((!vis[y]) && w<dis[y]) dis[y]=w; // 更新与该点相邻的点
        }
    }

    if(vis.count()<n) puts("orz");
    else{
        for(re int i=1;i<=n;i++) mst+=dis[i];
        cout<<mst<<endl;
    }
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
