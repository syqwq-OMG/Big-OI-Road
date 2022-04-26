#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;
int fa[N];
int n,m;
int ans;
int a,b;

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
    while(cin>>n>>m){
        ans=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        while(m--){
            cin>>a>>b; merge(a,b);
        }
        for(int i=1;i<=n;i++)
            if(fa[i]==i) ans++;
        //! ans 需要减一, 因为村之间的路 = 村庄数目 - 1
        cout<<ans-1<<endl;
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
