#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int u;
    int v;  // u->v
    int val;
};

const int N=1e4+5;
const int M=2e4+5;
int n,m,s,t;
int tot=0;
Edge edge[M];

int fa[N];

void add(int x,int y,int z){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].val=z;
}

bool cmp(const Edge& e1,const Edge& e2){
    return e1.val<e2.val;
}

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y){
    fa[x]=get(fa[y]);
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
    for(re int i=1;i<=n;i++) fa[i]=i;
    for(re int i=1;i<=m;i++){
        re int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
    }

    sort(edge+1,edge+1+m,cmp);
    // int cnt=0;   // 记录加入 MST 的边的数量
    for(re int i=1;i<=m;i++){
        int p=get(edge[i].u); int q=get(edge[i].v);
        if(p==q) continue;
        merge(p,q);

        if(get(s)==get(t)){
            cout<<edge[i].val<<endl;
            break;
        }
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
