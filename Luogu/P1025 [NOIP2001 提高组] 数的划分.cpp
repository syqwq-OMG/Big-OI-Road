#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

int n,k;
int cnt=0;

void dfs(int t,int sum,int tmp_max){    // 保持非严格单调递增
    if(t==k+1){
        if(sum==n)  cnt++;
        return;
    }
    for(re int i=tmp_max;sum+i*(k-t)<=n;i++){
        dfs(t+1,sum+i,i);
    }
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
    cin>>n>>k;
    dfs(1,0,1);
    cout<<cnt;

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

