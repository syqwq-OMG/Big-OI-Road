#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=1e3+5;
int n,x;
int use[N],win[N],lose[N];
int dp[N];

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>x;
    for(re int i=1;i<=n;i++) cin>>lose[i]>>win[i]>>use[i];
    for(re int i=1;i<=n;i++){   // 这一维是用来滚动的
        for(re int j=x;j>=0;j--){
            if(j>=use[i]) dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
            else dp[j]+=lose[i];
        }
    }
    cout<<5*dp[x]<<endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
