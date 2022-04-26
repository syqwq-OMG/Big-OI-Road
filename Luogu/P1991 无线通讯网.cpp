#include <bits/stdc++.h>
#define re register
using namespace std;

struct node{
    int u,v;
    double w;
};

const int P=505;
int s,p;
int tot=0;
node edge[P*P];
int x[P],y[P];

int fa[P];
int cnt=0;

bool cmp(const node& n1,const node& n2){
    return n1.w<n2.w;
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
    cin>>s>>p;
    for(re int i=1;i<=p;i++) cin>>x[i]>>y[i];
    for(re int i=1;i<=p;i++){
        for(re int j=i+1;j<=p;j++){
            edge[++tot].u=i; edge[tot].v=j;
            edge[tot].w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    for(re int i=1;i<=p;i++) fa[i]=i;
    sort(edge+1,edge+1+tot,cmp);
    for(re int i=1;i<=tot;i++){
        int a=get(edge[i].u); int b=get(edge[i].v);
        if(a==b) continue;
        merge(a,b);
        if(++cnt>=p-s){
            cout<<fixed<<setprecision(2)<<edge[i].w<<endl;
            break;
        }
    }
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
