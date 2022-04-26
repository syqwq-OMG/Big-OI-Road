#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int to,nxt,val;
};

struct node{
    int ver;
    int dis;
    inline bool operator <(const node& x) const{
        return dis>x.dis;
    }
};

const int N=1e3+5;
const int M=1e5+5;
const int MAXN=0x3f3f3f3f;
int n,m;
// G & G^T
int head[2][N];
Edge edge[2][M];
int tot[2]={0,0};
int ans=0;
int dis[2][N];
priority_queue<node> pq;
bitset<N> vis;  // 表示是否更新过

void add(int x,int y,int z,int _){
    edge[_][++tot[_]].to=y;
    edge[_][tot[_]].val=z;
    edge[_][tot[_]].nxt=head[_][x];
    head[_][x]=tot[_];
}

void dijkstra(int _){
    vis&=0;
    for(int i=0;i<N;i++) dis[_][i]=MAXN;

    dis[_][1]=0; pq.push((node){1,0});
    while(!pq.empty()){
        int x=pq.top().ver; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(re int i=head[_][x]; i; i=edge[_][i].nxt){
            int y=edge[_][i].to;
            int w=edge[_][i].val;
            if(dis[_][y]>dis[_][x]+w){
                dis[_][y]=dis[_][x]+w;
                pq.push((node){y,dis[_][y]});
            }
        }
    }
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
    for(re int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w,0);
        add(v,u,w,1);
    }
    dijkstra(0);
    dijkstra(1);
    for(re int i=2;i<=n;i++) ans+=dis[0][i]+dis[1][i];
    cout<<ans;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
