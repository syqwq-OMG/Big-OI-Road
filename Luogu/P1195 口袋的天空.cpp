#include <bits/stdc++.h>
#define re register
// #define luogu
using namespace std;

struct Edge{
    int u;
    int v;
    int val;
    bool operator <(const Edge& e) const{
        return val<e.val;
    }
};

const int N=1e3+5;
const int M=1e4+5;
int n,m,k;
int ans=0;
int cnt=0;	// 已经放入树中的边数 

int tot=0;
Edge edge[M]; 

int fa[N];

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

void add(int x,int y,int z){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].val=z;
}

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y){
    fa[get(x)]=get(y);
}

int main(){
    ios::sync_with_stdio(0);
#ifndef luogu
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
// ===================================================
    n=read(); m=read(); k=read();
    if(n-k>m){
        puts("No Answer");
        goto end;
    }
    for(re int i=1;i<=n;i++) fa[i]=i;
    
    for(re int i=1;i<=m;i++){
        re int a,b,c;
        a=read(); b=read(); c=read();
        add(a,b,c);
    }
    sort(edge+1,edge+1+m);
    for(re int i=1;i<=m;i++){
        int p=get(edge[i].u), q=get(edge[i].v);
        if(p==q) continue;
        merge(p,q);
        ans+=edge[i].val;
        if(++cnt==n-k) break;
    }
    write(ans);
// ===================================================
end:
    return 0;
}