#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int N=410;
const int dx[9]={0,1,-1,-1,1,2,2,-2,-2};
const int dy[9]={0,2,2,-2,-2,1,-1,-1,1};

int step[N][N];
struct node{
    int x,y;
    node(int X,int Y):x(X),y(Y) {}
};

int n,m,x,y;
queue<node> q;

inline bool check(int x,int y) {return x>=1 && x<=n && y>=1 && y<=m && (!step[x][y]);}

void print(){
    rep(i,1,n){
        rep(j,1,m)
            printf("%-5d", step[i][j]);
        printf("\n");
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
// ======================================================================
    cin>>n>>m>>x>>y;
    q.push(node(x,y));
    while(!q.empty()){
        int xx=q.front().x;
        int yy=q.front().y;
        q.pop();
        rep(i,1,8){
            int nx=xx+dx[i];
            int ny=yy+dy[i];
            if(!check(nx,ny)) continue;
            step[nx][ny]=step[xx][yy]+1;
            q.push(node(nx,ny));
        }
    }

    rep(i,1,n)
        rep(j,1,m)
            if(!step[i][j]) step[i][j]=-1;
    step[x][y]=0;

    print();

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

