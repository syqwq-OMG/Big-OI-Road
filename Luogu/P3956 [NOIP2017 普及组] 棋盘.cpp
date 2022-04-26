#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

struct node{
    int x,y;
    int coin;    // 当前所花费金币
    int color;  //当前格子颜色

    node(int _x,int _y,int _coin,int _color)
        :x(_x),y(_y),coin(_coin),color(_color) {}
    
    bool operator <(const node& n1) const {
        return this->coin>n1.coin;
    }
};

const int N=1005;
const int inf=0x3f3f3f3f;
const int dx[5]={0,0,0,-1,1};
const int dy[5]={0,-1,1,0,0};

int m,n;
int mapp[N][N]; // 0无色 1红色 2黄色
int coin=inf;
bool vis[N][N];

priority_queue<node> pq;

int read(){
    int sign=1,num=0;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') sign=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    return sign*num;
}

inline bool valid(int x,int y){
    return (!vis[x][y]) && x<=m&&x>0 && y<=m&&y>0;
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
    m=read(); n=read();
    rep(i,1,n){
        int x=read(),y=read(),c=read();
        mapp[x][y]=c+1;
    }

    pq.push(node(1,1,0,mapp[1][1])); vis[1][1]=1;
    while(!pq.empty()){
        node now=pq.top(); pq.pop();
        if(now.x==m && now.y==m){
            coin=min(coin,now.coin);
            break;
        }
        vis[now.x][now.y]=1;
        rep(i,1,4){
            int nx=now.x+dx[i]; int ny=now.y+dy[i];
            if(!valid(nx,ny)) continue;
            if(mapp[nx][ny]){   // 这个方格有颜色
                if(mapp[nx][ny]==now.color)
                    pq.push(node(nx,ny,now.coin,now.color));
                else
                    pq.push(node(nx,ny,now.coin+1,mapp[nx][ny]));
            }else{  // 方格无色
                if(now.color!=mapp[now.x][now.y]) continue; // 上一步使用过魔法, 无效
                pq.push(node(nx,ny,now.coin+2,now.color));   // 使用魔法, 与上一步颜色一样
                // pq.push(node(nx,ny,now.coin+3,(now.color==1)?2:1));  // 使用魔法, 与上一步颜色不同
            }
        }
    }

    if(coin==inf) cout<<-1;
    else cout<<coin;

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}