#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=5e5+5;
int n,m;
struct SegmentTree{
    int l,r;
    int sum;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
} tree[N*4];    // 开4倍大小
int a[N];

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

// 建树
void build(int p,int l,int r){
    l(p)=l; r(p)=r;
    if(l==r) {sum(p)=a[l]; return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

// 单点修改
void change(int p,int x,int v){
    if(l(p)==r(p)) {sum(p)=v; return;}
    int mid=(l(p)+r(p))>>1;
    if(x<=mid) change(p<<1,x,v);
    else change((p<<1)+1,x,v);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

// 区间查询
int ask(int p,int l,int r){
    if(l(p)>=l && r(p)<=r) return sum(p);
    int ans=0;
    int mid=(l(p)+r(p))>>1;
    if(l<=mid) ans+=ask(p<<1,l,r);
    if(r>mid) ans+=ask((p<<1)+1,l,r);
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
    for(re int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);   // 1是线段树的入口, 任何调用都从1开始
    while(m--){
        re int op,x,y; op=read(); x=read(); y=read();
        if(op==1) change(1,x,y);
        if(op==2){
            write(ask(1,x,y));
            puts("");
        }
    }
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
