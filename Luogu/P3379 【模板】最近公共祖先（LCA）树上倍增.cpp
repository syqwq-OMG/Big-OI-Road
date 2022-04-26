#include <bits/stdc++.h>
#define re register
#define gc getchar
using namespace std;

struct Edge{
    int to;
    int nxt;
    // int val;
};

const int N=5e5+5,M=5e5+5;
const int T=22;
int n,m,s;
int t;

int tot=0;
int head[N];
Edge edge[N<<1];

int d[N];    // 深度
int f[N][T];    // 倍增数组

queue<int> q;

int read(){
    int sign=1,num=0;
    char ch=gc();
    while(ch<'0' || ch>'9'){if(ch=='-') sign=-1;ch=gc();}
    while(ch>='0' && ch<='9') {num=num*10+ch-'0';ch=gc();}
    return sign*num;
}

void add(int x,int y){
    edge[++tot].to=y;
    // edge[tot].val=z;
    edge[tot].nxt=head[x];
    head[x]=tot;
}

inline void swap(int& x,int& y){
    x^=y;
    y^=x;
    x^=y;
}

void bfs(){
    d[s]=1; q.push(s);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(re int i=head[x];i;i=edge[i].nxt){
            int y=edge[i].to;
            if(d[y]) continue;
            d[y]=d[x]+1;
            f[y][0]=x;
            for(re int j=1;j<=t;j++)
                f[y][j]=f[f[y][j-1]][j-1];
            q.push(y);
        }
    }
}

int lca(int x,int y){
    if(d[x]>d[y]) swap(x,y);
    for(re int i=t;i>=0;i--)
        if(d[f[y][i]]>=d[x]) y=f[y][i];

    if(x==y) return x;

    for(re int i=t;i>=0;i--)
        if(f[y][i]!=f[x][i]) y=f[y][i], x=f[x][i];
    
    return f[x][0];
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
    n=read(); m=read(); s=read();
    t=(int)(log(n)/log(2))+1;

    for(re int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y); add(y,x);
    }

    bfs();

    for(re int i=1;i<=m;i++){
        int x=read(),y=read();
        cout<<lca(x,y)<<endl;
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
