#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e5+5;
int n;
int q,k;

int v[N];   // 记录 n 的最小质因子
int m;
int prime[N];

int read(){
    int sign=1,num=0;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') sign=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    return sign*num;
}

void write(int x){
    if(x<0) x=~x+1;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

// 线性筛
void primes(){
    memset(v,0,sizeof(v));
    m=0;
    for(re int i=2;i<=n;i++){   // 遍历每个数
        if(v[i]==0) v[i]=i, prime[++m]=i;
        for(re int j=1;j<=m;j++){   // 遍历已知素数
            if(prime[j]>v[i] || prime[j]>n/i) break;
            // 核心: prime 为 v[i*prime] 的最小质因子
            v[i*prime[j]]=prime[j];
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
    n=read(); q=read();
    primes();
    while(q--){
        k=read();
        write(prime[k]);
        puts(" ");
    }
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
