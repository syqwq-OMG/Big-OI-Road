// 边带权并查集
#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e3+5;
int fa[N];
int d[N];   // 0->同伙 1->异伙  与父亲节点的关系
int ans=0;
bool one[N],zero[N];
int n,m;
int a,b; char op;

int get(int x){
    if(fa[x]==x) return x;
    int root=get(fa[x]);
    d[x]^=d[fa[x]]; // 此时, x 的 fa[x] 还未更新
    return fa[x]=root;
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
    for(re int i=1;i<=n;i++) fa[i]=i;
    while(m--){
        cin>>op>>a>>b;
        int p=get(a); int q=get(b);
        if(op=='F'){
            if(p==q) continue;
            fa[p]=q; d[p]=d[a]^d[b]^0;
        }else{
            if(p==q) continue;
            fa[p]=q; d[p]=d[a]^d[b]^1;
        }
        // fa[p]=q;
        // if(op=='F') d[p]=d[a]^d[b]^0;
        // else d[p]=d[a]^d[b]^1;
    }
    for(re int i=1;i<=n;i++){
        int root=get(i);
        if(d[i]==0) zero[root]=1;
        else one[root]=1;
    }
    for(re int i=1;i<=n;i++)
        if(fa[i]==i) ans+=zero[i]+one[i];
    cout<<ans;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
