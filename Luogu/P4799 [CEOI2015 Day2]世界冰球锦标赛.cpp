#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
typedef long long ll;

const int N=45;
const int M=1e8;

ll n,m;
ll a[N];
ll ans=0;
vector<ll> lhalf, rhalf;
ll tmp;

template<typename T>
void read(T& _x){
    T sign=1, num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') sign=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    _x=sign*num;
}

// 处理好 k-1, 已经有的是 sum
void dfs(int l,int r,ll sum,vector<ll>& price){
    if(sum>m) return;
    if(l>r){
        price.push_back(sum);
        return;
    }
    dfs(l+1,r,sum,price);
    dfs(l+1,r,sum+a[l],price);
}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
// ======================================================================
    read(n); read(m);
    rep(i,1,n) read(a[i]);

    dfs(1,n/2,0,lhalf);
    dfs(n/2+1,n,0,rhalf);

    sort(rhalf.begin(),rhalf.end());
    for(auto& x:lhalf){
        ans+=upper_bound(rhalf.begin(),rhalf.end(),m-x)-rhalf.begin();
    }
    cout<<ans;

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

