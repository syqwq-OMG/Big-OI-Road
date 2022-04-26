#include <bits/stdc++.h>
#define re register
using namespace std;

//! 村庄是从 0 开始的, 所以代码要有一个偏移量 !
const int N=205;
const int MAXN=0x3f3f3f3f;
const int M=5e4+5;
int n,m,q;
int t[N];
int dis[N][N];  // 存完整的图
int stat=1;

void floyd(int k){
    for(re int st=1;st<=n;st++)
        for(re int en=1;en<=n;en++)
            if(dis[st][k]+dis[k][en]<dis[st][en])
                dis[st][en]=dis[en][st]=dis[st][k]+dis[k][en];
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
    cin>>n>>m;
    for(re int i=1;i<=n;i++)
        for(re int j=i+1;j<=n;j++)
            dis[i][j]=dis[j][i]=MAXN;
    for(re int i=1;i<=n;i++) cin>>t[i];
    while(m--){
        int i,j,w; cin>>i>>j>>w;
        i++, j++;   // 村庄偏移量
        dis[i][j]=dis[j][i]=w;
    }
    cin>>q;
    for(re int i=1;i<=q;i++){
        int x,y,tm; cin>>x>>y>>tm; x++,y++;
        while(t[stat]<=tm && stat<=n){
            floyd(stat);    // 一点点去更新
            stat++;
        }
        if(t[x]>tm || t[y]>tm || dis[x][y]==MAXN) cout<<-1<<endl;
        else cout<<dis[x][y]<<endl;
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
