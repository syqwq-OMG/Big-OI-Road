#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

struct rec{
    int x,y;
    rec(int _x,int _y):x(_x),y(_y){}
};

int n;
int mapp[5][7]; // mapp[x][y]
#define col(x,y) mapp[x][y]
bool is_remove[5][7];
#define isr(x,y) is_remove[x][y]
vector<pair<rec,int> > ans;
int version[8][5][7];

void swap(rec r1,rec r2){
    int tmp=col(r1.x,r1.y);
    col(r1.x,r1.y)=col(r2.x,r2.y);
    col(r2.x,r2.y)=tmp;
}

inline bool valid(int x,int y){
    return x>=0&&x<5 && y>=0&&y<7;
}

void update(){
    // 下沉
    rep(i,0,4)
        rep(j,0,6){
            if(!col(i,j)) continue;
            int nx=i;
            int ny=j-1;
            while(valid(nx,ny) && col(nx,ny)==0){
                swap(rec(i,j),rec(nx,ny));
                i=nx,j=ny;
                ny-=1;
            }
        }
}

bool remove(){
    // 消消乐
    bool is_change=0;
    rep(i,0,4){
        rep(j,0,6){ // 枚举中心格
            // 水平
            if(i>0&&i<4 && col(i,j)==col(i-1,j) && col(i,j)==col(i+1,j) && col(i,j))
                isr(i,j)=isr(i-1,j)=isr(i+1,j)=1, is_change=1;
            // 竖直
            if(j>0&&j<6 && col(i,j)==col(i,j-1) && col(i,j)==col(i,j+1) && col(i,j))
                isr(i,j)=isr(i,j-1)=isr(i,j+1)=1, is_change=1;
        }
    }
    if(!is_change) return 0;

    rep(i,0,4)
        rep(j,0,6)
            if(isr(i,j))
                col(i,j)=isr(i,j)=0;
    return 1;
}

void move(int x,int y,int dir){ // -1 ←  1 →
    // 左右移动
    swap(rec(x,y),rec(x+dir,y));
    update();
    while(remove()) update();
}

bool is_finished(){
    rep(i,0,4)
        if(col(i,0)) return 0;
    return 1;
}

void backpack(int k){
    rep(i,0,4)
        rep(j,0,6)
            version[k][i][j]=col(i,j);
}

void use_version(int k){
    rep(i,0,4)
        rep(j,0,6)
            col(i,j)=version[k][i][j];
}

void dfs(int k){
    if(is_finished()){
        for(auto& x:ans)
            cout<<x.first.x<<" "<<x.first.y<<" "<<x.second<<endl;
        exit(0);
    }
    if(k==n+1) return;
    backpack(k);
    rep(i,0,4){
        rep(j,0,6){
            if(!col(i,j)) continue;
            // →
            if(i<4 && col(i,j)!=col(i+1,j)){
                move(i,j,1);
                ans.push_back(make_pair(rec(i,j),1));
                dfs(k+1);
                use_version(k);
                ans.pop_back();
            }
            // ←
            if(i>0 && !col(i-1,j)){
                move(i,j,-1);
                ans.push_back(make_pair(rec(i,j),-1));
                dfs(k+1);
                use_version(k);
                ans.pop_back();
            }
        }
    }

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
    cin>>n;
    rep(i,0,4)
        rep(j,0,7){ //! 就是这个坑点, 就算这列全是满的, 也会有 0 
            int tmp; cin>>tmp;
            if(!tmp) break;
            else col(i,j)=tmp;
        }
    
    dfs(1);
    puts("-1");
// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}