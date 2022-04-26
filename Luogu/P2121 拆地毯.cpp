#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int u;
    int v;
    int beauty;
};

const int N=1e5+5;
int n,m,k;
int tot=0;
Edge edge[N];
int ans=0;

int cnt=0;
int fa[N];

bool cmp(const Edge& e1,const Edge& e2){
    return e1.beauty>e2.beauty;
}

void add(int x,int y,int z){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].beauty=z;
}

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y){
    fa[get(x)]=get(y);
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
    cin>>n>>m>>k;
    for(re int i=1;i<=n;i++) fa[i]=i;
    for(re int i=1;i<=m;i++){
        re int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
    }
    sort(edge+1,edge+1+m,cmp);
    for(re int i=1;i<=m;i++){
        int p=get(edge[i].u); int q=get(edge[i].v);
        if(p==q) continue;
        merge(p,q);
        ans+=edge[i].beauty;
        if(++cnt==k) break;
    }
    cout<<ans;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
