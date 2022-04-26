#include <bits/stdc++.h>
#define re register
#define ll long long
using namespace std;

const int N=1e4+5;
int n;
int x[N],y[N];
ll ans=0x7fffffffffffffff;

int read(){
    int sign=1,num=0; char ch=getchar();
    while(ch<'0' || ch>'9') { if(ch=='-') sign=-1; ch=getchar(); }
    while(ch>='0' && ch<='9') { num=num*10+ch-'0'; ch=getchar(); }
    return sign*num;
}

inline ll dist(int a,int b) { return (x[a]-x[b])*(x[a]-x[b])*1ll + (y[a]-y[b])*(y[a]-y[b])*1ll; }

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    n=read();
    for(re int i=1;i<=n;i++) x[i]=read(), y[i]=read();
    for(re int i=1;i<n;i++)
        for(re int j=i+1;j<=n;j++)
            ans=min(ans,dist(i,j));
    cout<<setprecision(4)<<fixed<<sqrt(ans);

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
