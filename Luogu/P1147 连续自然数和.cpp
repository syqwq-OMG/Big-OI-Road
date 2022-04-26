#include <bits/stdc++.h>
#define re register
using namespace std;

int m;
int f1,f2;

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>m; m<<=1;
    for(re int i=sqrt(m);i>1;i--){ // M 的较小因子
        if(m%i==0 && ((i+m/i)&1)){
            f1=i; f2=m/i;
            cout<<(f2-f1+1)/2<<" "<<(f1+f2-1)/2<<endl;
        }
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
