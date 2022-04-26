#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e4+5;
int n,k;
vector<int> v[N];

int dp[N];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>k;
    for(re int i=1;i<=k;i++){
        int st,t; cin>>st>>t;
        v[st].push_back(t);
    }
    for(re int i=n;i>0;i--){
        if(v[i].size()){
            for(re int j=0;j<v[i].size();j++)
                dp[i]=max(dp[i],dp[i+v[i][j]]);
        }else dp[i]=dp[i+1]+1;
    }
    cout<<dp[1]<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
