#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int mod=1e5+3;
int n,m;

// 快速幂
int power(int x,int p){
    int ret=1ll,base=x;
    for(; p; p>>=1){
        if(p&1) ret=ret*base*1ll%mod;
        base=base*base*1ll%mod;
    }
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
    cin>>m>>n;
    int tmp=(power(m,n)-m*1ll*power(m-1,n-1)%mod)%mod;
    if(tmp>0) cout<<tmp;
    else cout<<tmp+mod;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
