#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
const int MAXM=1e6+5;
int n,m;
bitset<MAXN> vis;
int cnt=0;
int ver[MAXN];
int head[MAXN];
int nxt[MAXM];
int x,y;

// 加边
void add(int u/*起始点*/,int v/*终止点*/){
    ver[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

// 站在当前节点
void dfs(int k){
    vis[ver[k]]=1;
    cout<<ver[k]<<" ";
    for(int i=head[y];i;i=nxt[i]){
        int y=ver[i];
        if(vis[y]) continue;
        //vis[y]=1;
        dfs(y);
    }
}

void bfs(){

}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ===================================
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>x>>y, add(x,y);
    for(int i=1;i<=9;i++) cout<<head[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt;i++) cout<<ver[i]<<" ";
    cout<<endl;
    dfs(1);
    cout<<endl;
    //vis&=0;
    //bfs();
    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
