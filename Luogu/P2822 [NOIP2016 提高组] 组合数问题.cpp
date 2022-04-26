#include <bits/stdc++.h>
#define re register
using namespace std;
typedef unsigned long long ull;

const int M=2e3+5;
int t;
int n,m,k;
ull c[M][M];
ull sum[M][M];

void make_table(){
    // 杨辉三角
    c[1][1]=1;
    for(re int i=0;i<=2000;i++) c[i][0]=1;
    for(re int i=1;i<=2000;i++)
        for(re int j=0;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
    // 处理二维前缀和数组
    for(re int i=1;i<=2000;i++){
        for(re int j=0;j<=i;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if(c[i][j]==0) sum[i][j]++; // 整除就加
        }
        //! 为啥????????????????????
        sum[i][i+1]=sum[i][i];//继承。
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
    cin>>t>>k;
    make_table();
    while (t--){
        cin>>n>>m;
        if(m>n) m=n;
        cout<<sum[n][m]<<endl;
    }
    
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
