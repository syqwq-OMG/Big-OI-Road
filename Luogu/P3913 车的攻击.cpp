#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=1e6+5;
int n,k;
int x[N],y[N];
int r,c;
int sx,sy;

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>k;
    for(re int i=0;i<k;i++)
        cin>>y[i]>>x[i];
    sort(x,x+k);
    sort(y,y+k);
    sx=unique(x,x+k)-x;
    sy=unique(y,y+k)-y;
    cout<<sx*n+sy*n-sx*sy;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
