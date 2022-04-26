#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int N=105;
const int dx[5]={0,0,0,-1,1};
const int dy[5]={0,-1,1,0,0};

int n,m,t;
int st_x,st_y,en_x,en_y;
int dp1[N][N],dp2[N][N];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
// ======================================================================
    cin>>n>>m>>t;
    rep(i,1,n)
        rep(j,1,m){
            char ch; cin>>ch;
            dp1[i][j]=dp2[i][j]=(ch=='.')?0:-1;
        }
    cin>>st_x>>st_y>>en_x>>en_y;
    
    dp1[st_x][st_y]=dp2[st_x][st_y]=1;
    rep(i,1,t){
        rep(x,1,n)
            rep(y,1,m){
                if(dp1[x][y]!=-1){
                    dp2[x][y]=0;
                    rep(d,1,4){
                        int nx=x+dx[d], ny=y+dy[d];
                        if(dp1[nx][ny]!=-1) dp2[x][y]+=dp1[nx][ny];
                    }
                }
            }
        memcpy(dp1,dp2,sizeof(dp2));
    }

    cout<<dp1[en_x][en_y];

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

