// Kruskal
#include <bits/stdc++.h>
#define re register
using namespace std;

// 边
struct edge{
    int u,v,val;    // u->v 边权val
};

const int M=2e5+5;
const int N=5e3+5;
int n,m;
int fa[N];
edge e[M];
int cnt=0;  // 加入树中的边数
int mst=0;

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y){
    fa[get(x)]=get(y);
}

bool cmp(const edge& e1, const edge& e2){
    return e1.val<e2.val;
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
    for(re int i=1;i<=n;i++) fa[i]=i;   //! 初始化 fa[]!!! QwQ
    for(re int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        e[i].u=a; e[i].v=b; e[i].val=c;
    }
    sort(e+1,e+1+m,cmp);
    for(re int i=1;i<=m;i++){
        int x=get(e[i].u); int y=get(e[i].v);
        if(x==y) continue;
        mst+=e[i].val;
        merge(x,y);
        if(++cnt==n-1) break;
    }

    if(cnt!=n-1) puts("orz");
    else cout<<mst<<endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
