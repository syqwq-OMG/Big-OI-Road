#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int p=1e5+3;
const int N=1e5+5;

int n,k;
int f[N];

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
    f[0]=1;
    rep(i,1,n){
        rep(j,1,min(k,i)){
            f[i]=(f[i]+f[i-j])%p;
        }
    }
    cout<<f[n];

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

