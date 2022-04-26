#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=103;
int r,c;
int a[N][N];    // a[r][c]
int dp[N][N];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int ans=-1;

// 记忆化搜索
int dfs(int x,int y){
    if(dp[y][x]!=-1) return dp[y][x];
    dp[y][x]=1;
    for(re int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 || nx>c || ny<1 || ny>r || a[ny][nx]>=a[y][x]) continue;
        dfs(nx,ny);
        dp[y][x]=max(dp[y][x],dp[ny][nx]+1);
    }
    return  dp[y][x];
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
    cin>>r>>c;
    for(re int i=1;i<=r;i++)
        for(re int j=1;j<=c;j++)
            cin>>a[i][j], dp[i][j]=-1;
    
    for(re int i=1;i<=r;i++)
        for(re int j=1;j<=c;j++){
            if(dp[i][j]==-1) ans=max(ans,dfs(j,i));
        }
    cout<<ans;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}