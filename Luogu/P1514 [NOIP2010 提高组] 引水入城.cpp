#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int N=505;
const int inf=0x3f3f3f3f;
const int dx[5]={0,0,-1,1,0};
const int dy[5]={0,-1,0,0,1};

struct node{
    int l;
    int r;
    node() { l=inf,r=-1; }
    node(int _l,int _r):l(_l),r(_r) {}
};
struct rec{
    int x;
    int y;
    rec(int _x,int _y):x(_x),y(_y) {}
};

int n,m;
int mapp[N][N]; // mapp[y,x]
bool v[N][N];   // v[x,y]
node city[N];   // 最后一行
int cnt=0;

bool valid(int x,int y){
    return (!v[x][y]) && x>0&&x<=m && y>0&&y<=n;
}

// 从最后一行 x 位置开始搜索, 看哪些水库能够灌溉到 [必然是连续的区间]
void bfs(int x){
    memset(v,0,sizeof(v));
    queue<rec> q;
    q.push(rec(x,n)); v[x][n]=1;
    while(!q.empty()){
        rec cur=q.front(); q.pop();
        rep(i,1,4){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(!valid(nx,ny)) continue;
            if(mapp[ny][nx]>mapp[cur.y][cur.x]){
                v[nx][ny]=1;
                q.push(rec(nx,ny));
                if(ny==1){
                    city[x].l=min(city[x].l,nx);
                    city[x].r=max(city[x].r,nx);
                }
            }
        }
    }
}

bool cmp(node n1,node n2){
    if(n1.l!=n2.l) return n1.l<n2.l;
    return n1.r<n2.r;   // 优先满足小区间
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
    rep(i,1,n) rep(j,1,m) cin>>mapp[i][j];
    rep(i,1,m) bfs(i);
    // rep(i,1,m) cout<<"city_"<<i<<":"<<city[i].l<<" "<<city[i].r<<endl;
    
    // 贪心 - 线段覆盖
    rep(i,1,m)
        if(city[i].l>city[i].r)
            cnt++;
    if(cnt){
        if(n!=1) cout<<0<<endl<<cnt<<endl;
        else cout<<1<<endl<<cnt<<endl;
        goto end;
    } else {
        cnt=0;
        sort(city+1,city+1+m,cmp);
        int last=0; // 上一个水电站
        rep(i,1,m){
            if(city[i].l<=last && city[i].r>=last) continue;
            cnt++;
            last=city[i].r;
        }
        cout<<1<<endl<<cnt<<endl;
    }

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}