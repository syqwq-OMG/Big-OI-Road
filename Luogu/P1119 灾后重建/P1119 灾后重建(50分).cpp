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
int stat=-1,ans[N][N];  // 答案

void floyd(int tm){
    for(re int i=1;i<=n;i++)
        for(re int j=i+1;j<=n;j++){
            if(tm<t[i] || tm<t[j] || dis[i][j]==MAXN) ans[i][j]=ans[j][i]=MAXN;
            else ans[i][j]=ans[j][i]=dis[i][j];
        }
            
    for(re int k=1;k<=n;k++)
        for(re int st=1;st<=n;st++)
            for(re int en=1;en<=n;en++)
                //// if(tm>=t[k] && tm>=t[st] && tm>=t[en] && ans[st][k]+ans[k][en]<ans[st][en])
                if(ans[st][k]+ans[k][en]<ans[st][en])
                    ans[st][en]=ans[st][k]+ans[k][en];
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
        int x,y,ti; cin>>x>>y>>ti; x++,y++;
        if(stat==ti){
            if(ans[x][y]==MAXN) cout<<-1<<endl;
            else cout<<ans[x][y]<<endl;
        }else{
            floyd(ti); stat=ti;
            if(ans[x][y]==MAXN) cout<<-1<<endl;
            else cout<<ans[x][y]<<endl;
        }
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
