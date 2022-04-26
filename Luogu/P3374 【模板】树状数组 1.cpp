#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=5e6+5;
int n,m;
int a[N],c[N];
int p,q,op;

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
    if(x<0){
        putchar('-');
        x=~x+1;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline int lowbit(int x){
    return x&(-x);
}

inline void add(int x,int y){
    for(; x<=n; x+=lowbit(x)) c[x]+=y;
}

inline int ask(int x){
    int ans=0;
    for(; x; x-=lowbit(x)) ans+=c[x];
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
// ======================================================================
    n=read(); m=read();
    for(re int i=1;i<=n;i++) a[i]=read(), add(i,a[i]);
    while(m--){
        op=read(); p=read(); q=read();
        if(op==1) add(p,q);
        if(op==2){
            write(ask(q)-ask(p-1));
            puts("");
        }
    }

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
