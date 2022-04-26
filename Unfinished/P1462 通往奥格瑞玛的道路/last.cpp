#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int to;
    int nxt;
    int blood;
};

struct node{
    int ver;
    int dis;
    bool operator <(const node& n) const{
        return dis>n.dis;
    }
};

const int N=1e5+5;
const int M=5e5+5;
const int INF=0x3f3f3f3f;
int n,m,b;
int f[N];
int dis[N];
bitset<N> vis;

int tot=0;
int head[N];
Edge edge[M];

int l,r;

void add(int x,int y,int z){
    edge[++tot].to=y;
    edge[tot].nxt=head[x];
    edge[tot].blood=z;
    head[x]=tot;
}

// 二分判定
bool dijkstra(int k){
    vis&=0;
    memset(dis,0x3f,sizeof(dis));
    priority_queue<node> pq;
    // 按照 血量 Dijkstra
    dis[1]=0; pq.push((node){1,0});
    while(pq.size()){
        int x=pq.top().ver; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            int w=edge[i].blood;
            if(dis[x]+w<dis[y] && f[y]<=k){
                dis[y]=dis[x]+w;
                pq.push((node){y,dis[y]});
            }
        }
    }
    return dis[n]<=b;
}

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>m>>b;
    for(re int i=1;i<=n;i++) cin>>f[i];
    for(re int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    if(!dijkstra(INF)) puts("AFK");
    else{
        // 类似做了一个离散化处理
        sort(f+1,f+1+n);
        l=1, r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(dijkstra(f[mid])) r=mid;
            else l=mid+1;
        }
        cout<<f[l]<<endl;
    }


    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
