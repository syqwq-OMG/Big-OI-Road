#include <bits/stdc++.h>
using namespace std;

const int N=55;
const int p=1000000007;
int n;
int a[N];
long long ans=1;

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
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=0;i<=n;i++,j++){
        ans=1ll*ans*(a[i]-j)%p;
    }
    cout<<ans;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
