#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

const int N=10;
const int node_n=5;
const int switch_from[5]={0, 1,1,2,2};
const int switch_to[5]={0, 5,2,3,4};

int cir[N][N];

int cnt=0;

inline void add(int u,int v,int w){cir[u][v]=cir[v][u]=w;}

void init(){
    memset(cir,0,sizeof(cir));
    rep(i,1,node_n) add(i,i,1);
    add(3,5,1); add(4,5,1);
}

bool floyd(){
    rep(k,1,node_n)
        rep(i,1,node_n)
            rep(j,1,node_n)
                if(cir[i][k]&&cir[k][j]) cir[i][j]=1;
    return cir[1][5];
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
    rep(i,0,(1<<4)-1){
        init();
        rep(j,0,3){
            add(switch_from[j+1],switch_to[j+1],(i>>(3-j))&1);
            cout<<((i>>(3-j))&1);
        }
        cout<<"-->"<<floyd()<<endl;
        if(floyd()) cnt++;
    }
    cout<<cnt;
// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

