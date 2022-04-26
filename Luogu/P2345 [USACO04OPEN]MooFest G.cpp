#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=2e4+5;
int n,maxn=-1;
struct cow{
    int x;
    int v;
    bool operator <(const cow c1) const{
        return v<c1.v;
    }
} c[N];
int tcnt[N],tval[N];
int ans=0;

int read(){
    int sign=1,num=0; char ch=getchar();
    while(ch<'0' || ch>'9') { if(ch=='-') sign=-1; ch=getchar(); }
    while(ch>='0' && ch<='9') { num=num*10+ch-'0'; ch=getchar(); }
    return sign*num;
}

inline int lowbit(int x){
    return x&-x;
}

inline void addcnt(int x){
    for(; x<=maxn; x+=lowbit(x))
        tcnt[x]++;
}

inline void addval(int x,int y){
    for(; x<=maxn; x+=lowbit(x))
        tval[x]+=y;
}

inline int askcnt(int x){
    int ret=0;
    for(; x; x-=lowbit(x)) ret+=tcnt[x];
    return ret;
}

inline int askval(int x){
    int ret=0;
    for(; x; x-=lowbit(x)) ret+=tval[x];
    return ret;
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
    for(re int i=1;i<=n;i++) c[i].v=read(), c[i].x=read(), maxn=max(maxn,c[i].x);
    sort(c+1,c+1+n);
    for(re int i=1;i<=n;i++){
        addval(c[i].x,c[i].x);
        addcnt(c[i].x);
        ans+=c[i].v*
            (c[i].x*askcnt(c[i].x-1)-askval(c[i].x-1)+
            askval(maxn)-askval(c[i].x)-c[i].x*(askcnt(maxn)-askcnt(c[i].x)));
    }
    cout<<ans;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
