#include <bits/stdc++.h>
#define re register
using namespace std;

struct Edge{
    int u;
    int v;
    int val;
};

const int B=505;
int a,b;
int tot=0;
Edge k[B];
int mst=0;
int cnt=0;

int fa[B];

bool cmp(const Edge& e1,const Edge& e2){
    return e1.val<e2.val;
}

void add(int x,int y,int z){
    k[++tot].u=x;
    k[tot].v=y;
    k[tot].val=z;
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
    cin>>a>>b;
    for(re int i=1;i<=b;i++) fa[i]=i;
    for(re int i=1;i<=b;i++){
        for(re int j=1;j<=b;j++){
            re int tmp; cin>>tmp;
            if(i<j && !tmp) add(i,j,tmp-a);
        }
    }

    sort(k+1,k+1+tot,cmp);
    for(re int i=1;i<=tot;i++){
        int p=get(k[i].u); int q=get(k[i].v);
        if(p==q) continue;
        merge(p,q);
        mst+=k[i].val;
        if(++cnt==b-1) break;
    }

    cout<<a*b+mst<<endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
