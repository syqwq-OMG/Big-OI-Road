#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int M=1e4+5;
const int T=1e7+5;
int m,t;
int dp[T];
int v[M],w[M];

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>t>>m;
    for(re int i=1;i<=m;i++) cin>>v[i]>>w[i];
    for(re int i=1;i<=m;i++){
        for(re int j=v[i];j<=t;j++){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[t]<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
