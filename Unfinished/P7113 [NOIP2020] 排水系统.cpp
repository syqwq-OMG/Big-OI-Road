#include <bits/stdc++.h>
#define re register
using namespace std;

// 分数
struct frac{
    int p;
    int q;  // p/q
};

// 最大公约数
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

// 最小公倍数
int lcm(int x,int y){
    return x*(y/gcd(x,y));
}

// 分数加法
frac add_frac(const frac& f1,const frac& f2){
    int Q=lcm(f1.q,f2.q);
    int P=f1.p*(Q/f1.q)+f2.p*(Q/f2.q);
    int tmp=gcd(P,Q);
    Q/=tmp; P/=tmp; // 约分
    return (frac){P,Q};
}

struct Edge{
    int to;
    int nxt;
};

const int N=1e5+5;
const int M=10;
int n,m;

int tot=0;
int head[N];
Edge edge[N<<1];
frac water[N];
int in[N],out[N];
queue<int> q;

// 加边
void add(int x,int y){
    edge[++tot].to=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
    in[y]++; out[x]++;
}

// 输出分数
void print(const frac& f){
    cout<<f.p<<" "<<f.q<<endl;
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
    for(re int i=1;i<=n;i++){
        water[i].p=0; water[i].q=1; // 0/1=0
        re int tmp,d; cin>>d;
        while(d--){
            cin>>tmp;
            add(i,tmp);
        }
    }

    // for(re int i=1;i<=n;i++)
    //     cout<<out[i]<<endl;
    for(re int i=1;i<=n;i++)
        if(in[i]==0){
            water[i]=(frac){1,1};
            q.push(i);
        }
    while(q.size()){
        int x=q.front(); q.pop();
        if(out[x]==0) break;    // 到底了
        // cout<<x<<endl;
        for(re int i=head[x]; i; i=edge[i].nxt){
            int y=edge[i].to;
            // cout<<x<<"->"<<y<<endl;
            water[y]=add_frac(water[y],(frac){water[x].p,water[x].q*out[x]});
            if(--in[y]==0) q.push(y);
        }
    }

    for(re int i=1;i<=n;i++)
        if(!out[i]) print(water[i]);
    // print(add_frac((frac){1,3},(frac){2,4}));
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
