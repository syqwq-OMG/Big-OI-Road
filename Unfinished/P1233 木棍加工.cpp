#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=5e3+5;
int n;
struct node{int l,w;} a[N];
int f[N],pre[N];
int ans=0;

int read(){
    int sign=1,num=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
    return sign*num;
}

bool cmp(const node n1,const node n2){
    if(n1.l!=n2.l) return n1.l>n2.l;
    return n1.w>n2.w;
}

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    n=read();
    for(re int i=1;i<=n;i++) a[i].l=read(),a[i].w=read();
    sort(a+1,a+1+n,cmp);
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<i;j++)
            if(a[j].w>=a[i].w && f[j]+1>f[i])
                f[i]=f[j]+1,pre[i]=j;
    for(re int i=1;i<=n;i++) ans+=pre[i]==0;
    cout<<ans;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
