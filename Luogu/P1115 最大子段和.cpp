#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=2e5+5;
int n,a[N];
struct SegmentTree{
    int l,r;    // 区间的左右端点
    int lmax,rmax;  // lmax 从左开始的最大值, rmax同理
    int maxx;   // 区间的最大值
    int sum;    // 区间和
} tr[N<<2];

int read(){
    int sign=1,num=0; char ch=getchar();
    while(ch<'0' || ch>'9') { if(ch=='-') sign=-1; ch=getchar(); }
    while(ch>='0' && ch<='9') { num=num*10+ch-'0'; ch=getchar(); }
    return sign*num;
}

inline int max(int a,int b,int c) { return max(max(a,b),c); }

void push_up(int p){
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
    tr[p].lmax=max(tr[p<<1].lmax,tr[p<<1].sum+tr[p<<1|1].lmax);
    tr[p].rmax=max(tr[p<<1|1].rmax,tr[p<<1|1].sum+tr[p<<1].rmax);
    tr[p].maxx=max(tr[p<<1].maxx,tr[p<<1|1].maxx,tr[p<<1].rmax+tr[p<<1|1].lmax);
}

void build(int p,int l,int r){
    tr[p].l=l; tr[p].r=r;
    if(l==r){
        tr[p].sum=tr[p].maxx=tr[p].lmax=tr[p].rmax=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
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
    n=read();
    for(re int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    cout<<tr[1].maxx;   // tr[1] ==> [1,n]

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
