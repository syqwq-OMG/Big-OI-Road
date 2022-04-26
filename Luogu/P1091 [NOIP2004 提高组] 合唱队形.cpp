#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=105;
int n;
int t[N];
int f[2][N];    // 0/1 -> 正序/逆序
int ans=-1;

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
    for(re int i=1;i<=n;i++) cin>>t[i];

    // 正序
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<i;j++)
            if(t[j]<t[i]) f[0][i]=max(f[0][i],f[0][j]+1);
    // 逆序
    for(re int i=n;i>=1;i--)
        for(re int j=n;j>i;j--)
            if(t[j]<t[i]) f[1][i]=max(f[1][i],f[1][j]+1);

    for(re int i=1;i<=n;i++) ans=max(ans,f[0][i]+f[1][i]);
    cout<<n-ans-1;  // 自己没算

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
