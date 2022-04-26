#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull n,a,b;

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n;
    a=n>>16;
    b=n-(a<<16);
    n=(b<<16)+a;
    cout<<n;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
