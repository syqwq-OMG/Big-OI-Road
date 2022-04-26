#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e5+5;
int n,m;
int a[N];
int f[N][16];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void ST_prework(){
    for(re int i=1;i<=n;i++) f[i][0]=a[i];
    int t=log(n)/log(2);
    for(re int j=1;j<=t;j++)    // 区间长度
        for(re int i=1;i<=n-(1<<j)+1;i++)   // 左端点
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int ST_query(int l,int r){
    int t=log(r-l+1)/log(2);
    return max(f[l][t],f[r-(1<<t)+1][t]);
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
    n=read(); m=read();
    for(re int i=1;i<=n;i++) a[i]=read();
    ST_prework();
    while(m--){
        re int l=read(); re int r=read();
        cout<<ST_query(l,r)<<endl;
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
