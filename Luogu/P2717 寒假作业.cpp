#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=1e5+5;
int n,k;
int ans=0;
int a[N],tmp[N],sum[N];

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

void merge_sort(int s,int t){
    if(s==t) return;
    int mid=(s+t)>>1;
    merge_sort(s,mid);
    merge_sort(mid+1,t);
    int l=s, r=mid+1, pos=l;
    while(l<=mid && r<=t){
        if(sum[l]<=sum[r]){
            tmp[pos++]=sum[l++];
            ans+=t-r+1;
        }else tmp[pos++]=sum[r++];
    }
    while(l<=mid) tmp[pos++]=sum[l++];
    while(r<=t) tmp[pos++]=sum[r++];
    for(re int i=s;i<=t;i++) sum[i]=tmp[i];
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
    n=read(); k=read();
    for(re int i=1;i<=n;i++) a[i]=read()-k, sum[i]=sum[i-1]+a[i];
    merge_sort(0,n);
    write(ans);

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}