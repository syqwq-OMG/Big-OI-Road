#include <bits/stdc++.h>
#define re register
#define int unsigned long long
using namespace std;

int a,b,aa,bb,p,s=1;

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>a>>b>>p; aa=a,bb=b;

    for(; bb; bb>>=1){
        if(bb&1) s=s*aa*1ll%p;
        aa=aa*aa*1ll%p;
    }
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<s;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}