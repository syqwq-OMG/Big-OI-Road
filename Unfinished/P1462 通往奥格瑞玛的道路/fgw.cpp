#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

typedef priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > PQ;

const int N=1e4+10,M=1e5+10,INF=0x3f3f3f3f;
int n,m,b,x,y,z,l=INF,r,mid,f[N],head[N],nxt[M],to[M],val[M],tot,dis[N];
bool vis[N];
PQ q;

inline int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline void add(int x,int y,int z)
{
    val[++tot]=z;
    to[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dijkstra(int t)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[1]=0;
    PQ empty;
    swap(q,empty);
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int x=q.top().second;q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=to[i],z=val[i];
            if(f[y]>t||vis[y]) continue;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                q.push(make_pair(dis[y],y));
            }
        }
    }
}

int main()
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

    n=read(),m=read(),b=read();
    for(int i=1;i<=n;i++)
    {
        f[i]=read();
        l=min(l,f[i]),r=max(r,f[i]);
    }
    l=max(l,f[1]);
    for(int i=1;i<=m;i++)
    {
        x=read(),y=read(),z=read();
        add(x,y,z),add(y,x,z);
    }
    while(l<r)
    {
        mid=(l+r)>>1;
        dijkstra(mid);
        if(dis[n]<=b) r=mid;
        else l=mid+1;
    }
    if(dis[n]>b) dijkstra(l);
    if(dis[n]<=b) write(l);
    else printf("AFK");

end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}