#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e3+5;
int n;
int a[N][N];
int dp[N][N];

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
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<=i;j++)
            cin>>a[i][j];
    for(re int i=n;i>0;i--)
        for(re int j=1;j<=i;j++)
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
    
    cout<<dp[1][1];
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
