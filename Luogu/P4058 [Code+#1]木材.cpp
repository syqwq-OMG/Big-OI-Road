#include <bits/stdc++.h>
#define re register
#define int unsigned long long
using namespace std;

const int N=2e5+5;
int n,s,l;
int h[N],a[N];

int le,ri;
int t[N];

bool valid(int day){
    for(re int i=1;i<=n;i++) t[i]=h[i]+a[i]*day;
    sort(t+1,t+1+n,greater<int>()); // 从大到小
    int tot=0;
    for(re int i=1;t[i]>=l && i<=n;i++) tot+=t[i];
    return tot>=s;
}

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n>>s>>l;
    for(re int i=1;i<=n;i++) cin>>h[i];
    for(re int i=1;i<=n;i++) cin>>a[i];
    le=0, ri=1e18;
    while(le<ri){
        int mid=(le+ri)>>1;
        if(valid(mid)) ri=mid;
        else le=mid+1;
    }
    cout<<le<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
