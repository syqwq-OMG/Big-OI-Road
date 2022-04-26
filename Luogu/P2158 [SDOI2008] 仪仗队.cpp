#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=4e4+5;
int n;
int m=0,prime[N],v[N];
int phi[N];
int ans=0;

void euler(int x){
    for(re int i=2;i<=x;i++){
        if(v[i]==0) v[i]=i,prime[++m]=i,phi[i]=i-1;
        for(re int j=1;j<=m;j++){
            if(prime[j]>v[i] || prime[j]>x/i) break;
            v[i*prime[j]]=prime[j];
            /*
            p|n && p^2|n => euler(n)=euler(n/p)*p
            p|n && p^2 not|n => euler(n)=euler(n/p)*(p-1)
            此处 p=prime[j] , n/p=i
            判断 p^2|n <=> 判断 p|n/p
            */
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
        }
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
    cin>>n;
    if(n==1) {puts("0"); goto end;} // 特判第一个点
    euler(n);
    for(re int i=2;i<n;i++) ans+=phi[i]<<1;
    cout<<ans+3;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
