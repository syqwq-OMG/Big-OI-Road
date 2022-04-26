// P4017 最大食物链计数
#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005;
const int p=80112002;
int n,m;
int u,v;
vector<int> head[MAXN];
vector<int> prv[MAXN];
int deg[MAXN];
int cnt=0,a[MAXN];  // 拓扑序
int w[MAXN];    // way
int ans=0;

void add(int x,int y){
    head[x].push_back(y);
    prv[y].push_back(x);
    deg[y]++;
}

// 拓扑排序
void topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(deg[i]==0){
            q.push(i);
            w[i]++;
        }
    while(!q.empty()){
        int v=q.front(); q.pop();
        a[++cnt]=v;
        for(int i=0;i<head[v].size();i++){
            int y=head[v][i];
            if(--deg[y]==0) q.push(y);
        }
    } 
}

void solve(){
    for(int i=2;i<=n;i++){
        int y=a[i];
        for(int j=0;j<prv[y].size();j++){
            int z=prv[y][j];
            //! int z=prv[y][i];
            w[y]=(w[y]+w[z])%p;
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
    for(int i=0;i<m;i++){
        cin>>u>>v;
        add(u,v);
    }
    // for(int i=1;i<=n;i++) cout<<deg[i]<<" ";
    topsort();
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    solve();
    for(int i=1;i<=n;i++){
        if(head[i].size()==0) ans=(ans+w[i])%p;
    }
    cout<<ans<<endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
