// SPFA
#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e4+5;
const int MAXN=(1<<31)-1;
int n,m,s;
vector< pair<int,int> > head[N];
queue<int> q;
bitset<N> existed;
int dis[N];

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
    for(int i=0;i<N;i++) dis[i]=MAXN;
    cin>>n>>m>>s;
    for(re int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
    }

    dis[s]=0; q.push(s); existed[s]=1;
    while(!q.empty()){
        int x=q.front(); q.pop(); existed[x]=0;
        for(re int i=0;i<head[x].size();i++){
            int y=head[x][i].first;
            int w=head[x][i].second;
            if(dis[x]+w<dis[y]){
                dis[y]=dis[x]+w;
                if(!existed[y]){
                    q.push(y); existed[y]=1;
                }
            }
        }
    }
    for(re int i=1;i<=n;i++) cout<<dis[i]<<" ";

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
