#include <bits/stdc++.h>
#define re register
# define lll __int128   // 懒得写高精度
using namespace std;

const int N=85;
const int M=85;
int n,m;
int a[N][M];
lll f[N][M];
lll ans=0;
lll base[N]={1};    // 一定要做一个这个数组, 不然直接用位运算会爆掉的

// 精心设计的 print() 函数
void print(lll x){
    if(x==0) return;
    if(x) print(x/10);
    putchar(x%10+'0');
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
    cin>>n>>m;
    for(re int i=1;i<=M;i++) base[i]=base[i-1]<<1;
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<=m;j++)
            cin>>a[i][j];
    
    for(re int i=1;i<=n;i++){   // 第几层
        memset(f,0,sizeof(f));
        lll tmp=-1;
        for(re int l=1;l<=m;l++)
            for(re int r=m;r>=l;r--){
                re int k=l-r+m-1;   // 第几次取
                f[l][r]=max(f[l-1][r]+(a[i][l-1]*base[k]),f[l][r+1]+(a[i][r+1]*base[k]));
            }
        for(re int j=1;j<=m;j++) tmp=max(tmp,f[j][j]+(a[i][j]*base[m]));
        ans+=tmp;
    }
    if(ans==0) puts("0");
    else print(ans);

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
