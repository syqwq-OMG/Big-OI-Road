#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=6e3+5;
int n;
int root;
bool fa[N];
int h[N];
int f[N][2];    // 0/1 -> 不选/选

int tot=0;
int head[N];
struct Edge{
    int to,nxt;
} edge[N*N];

void add(int x,int y){
    edge[++tot].to=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
    fa[y]=1;
}

void dp(int x){
    f[x][0]=0;
    f[x][1]=h[x];
    for(re int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        dp(y);
        f[x][0]+=max(f[y][0],f[y][1]);
        f[x][1]+=f[y][0];
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
    cin>>n;
    for(re int i=1;i<=n;i++) cin>>h[i];
    for(re int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        add(b,a);
    }
    // 找根
    for(re int i=1;i<=n;i++)
        if(!fa[i]){
            root=i;
            break;
        }
    dp(root);
    cout<<max(f[root][0],f[root][1]);
// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
