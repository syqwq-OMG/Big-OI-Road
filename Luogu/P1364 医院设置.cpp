#include <bits/stdc++.h>
using namespace std;

int n;
int w[105];
int dis[105][105];
int ans=0x3f3f3f3f;
int tmp;

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ===================================
    cin>>n;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int u,v,x;
        cin>>x>>u>>v;
        if(u!=0) dis[i][u]=dis[u][i]=1;
        if(v!=0) dis[i][v]=dis[v][i]=1;
        w[i]=x;
    }
    // Floyd
    for(int k=1;k<=n;k++)
        for(int st=1;st<=n;st++)
            for(int en=1;en<=n;en++)
                if(dis[st][k]+dis[k][en]<dis[st][en])
                    dis[st][en]=dis[en][st]=dis[st][k]+dis[k][en];
    for(int pos=1;pos<=n;pos++){
        tmp=0;
        for(int i=1;i<=n;i++)
            tmp+=dis[pos][i]*w[i];
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
