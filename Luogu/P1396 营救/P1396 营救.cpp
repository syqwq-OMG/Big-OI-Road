#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int to;
    int nxt;
    int val;
};

struct node{
    int ver;
    int val;
    bool operator <(const node& n) const{
        return val>n.val;   // 小根堆
    }
};

const int N=1e4+5;
const int M=2e4+5;
int n,m,s,t;
int tot=0;
int head[N];
Edge edge[M<<1];

int dis[N];
bitset<N> vis;

void add(int x,int y,int z){
    edge[++tot].to=y;
    edge[tot].val=z;
    edge[tot].nxt=head[x];
    head[x]=tot;
}

void dijkstra(){
    vis=0;
    memset(dis,0x3f,sizeof(dis));
    priority_queue<node> pq;

    dis[s]=0; pq.push((node){s,0});
    while(pq.size()){
        int x=pq.top().ver; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            int w=max(dis[x],edge[i].val);  // 这一路的最大值
            if(w<dis[y]){   // 到这个点的最小值
                dis[y]=w;
                pq.push((node){y,dis[y]});
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
    cin>>n>>m>>s>>t;
    for(re int i=1;i<=m;i++){
        re int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra();
    cout<<dis[t]<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
