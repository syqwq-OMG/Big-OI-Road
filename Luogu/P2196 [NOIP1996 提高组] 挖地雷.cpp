#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int to; // 当前节点编号
    int nxt;   // 后继结点索引
};

const int N=25;
int n;
int path[N];
int in[N];
vector<int> prv[N];
int val[N];
int dp[N];
int ans=0;

int tot=0;
int head[N];
Edge edge[(N*N)<<1];

queue<int> q;

void add(int x,int y){
    edge[++tot].to=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
    prv[y].push_back(x);
    in[y]++;
}

void dfs(int x){
    if(x==0) return;
    dfs(path[x]);
    cout<<x<<" ";
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
    cin>>n;
    for(re int i=1;i<=n;i++) cin>>val[i];
    for(re int i=1;i<n;i++)
        for(re int j=i+1;j<=n;j++){
            int tmp; cin>>tmp;
            if(tmp) add(i,j);
        }

    // 拓扑排序
    for(re int i=1;i<=n;i++) if(!in[i]) q.push(i),dp[i]=val[i];
    while(!q.empty()){
        int x=q.front(); q.pop();
        // 前驱结点 DP
        for(re int i=0;i<prv[x].size();i++)
            if(dp[x]<dp[prv[x][i]]+val[x])
                dp[x]=dp[prv[x][i]]+val[x], path[x]=prv[x][i];
        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            if(--in[y]==0) q.push(y);
        }
    }

    for(re int i=1;i<=n;i++) if(dp[i]>dp[ans]) ans=i;
    dfs(ans);
    cout<<endl<<dp[ans]<<endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
