// 扩展域并查集
#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e3+5;
int fa[N<<1];
int n,m;
int ans=0;
int a,b; char op;

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
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
    for(re int i=1;i<=(n<<1);i++) fa[i]=i;
    while(m--){
        cin>>op>>a>>b;
        int x_f=a, x_e=a+n;
        int y_f=b, y_e=b+n;
        if(op=='F'){
            fa[get(x_f)]=get(y_f);
            //fa[get(x_e)]=get(y_e);
        }else{
            fa[get(y_e)]=get(x_f);
            fa[get(x_e)]=get(y_f);
        }
    }
    for(re int i=1;i<=n;i++) if(fa[i]==i) ans++;
    cout<<ans;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
