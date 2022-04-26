#include <bits/stdc++.h>
using namespace std;

const int N=5005;
int fa[N];
int n,m,p;

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
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) fa[i]=i;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(get(a)!=get(b)) merge(a,b);
    }
    while(p--){
        int a,b;
        cin>>a>>b;
        if(get(a)==get(b)) puts("Yes");
        else puts("No");
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
