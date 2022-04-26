#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e5+5;
int n;
int p1[N],p2[N];
int tmp;
int m[N];   // 映射

int len=0,f[N];

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
    for(re int i=1;i<=n;i++) cin>>p1[i];    
    for(re int i=1;i<=n;i++){
        cin>>tmp; m[tmp]=i;
    }
    for(re int i=1;i<=n;i++) p2[i]=m[p1[i]];
    for(re int i=1;i<=n;i++){
        if(p2[i]>f[len]) f[++len]=p2[i];
        else{
            int p=upper_bound(f+1,f+1+len,p2[i])-f;
            f[p]=p2[i];
        }
    }
    cout<<len<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
