#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int N=4e3+5;
const int M=13000+5;

int n,m;
int v[N],w[N];
int dp[M];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
// ======================================================================
    cin>>n>>m;
    rep(i,1,n) cin>>v[i]>>w[i];
    rep(i,1,n)
        per(j,m,v[i])
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    cout<<dp[m];
// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

