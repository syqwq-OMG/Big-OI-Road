#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1505;
vector< pair<int,int> > head[N]; // u<v,w>
int n,m;
int u,v,w;
int dis[N];
queue<int> q;
bitset<N> vis;

// 加边 (u, v, w)
void add(int x,int y,int z){
    head[x].push_back(make_pair(y,z));
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
    for(re int i=1;i<=n;i++) dis[i]=-1;
    for(re int i=0;i<m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    //? LPFA (Longest Path Fastest Algorithm) doge
    dis[1]=0; q.push(1); vis[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(re int i=0;i<head[x].size();i++){
            int to=head[x][i].first;
            int weight=head[x][i].second;
            if(dis[x]+weight>dis[to]){
                dis[to]=dis[x]+weight;
                if(!vis[to]) {
                    q.push(to);
                    vis[to]=1;
                }
            }
        }
    }
    cout<<dis[n]<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
