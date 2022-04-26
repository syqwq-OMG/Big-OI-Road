#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
#define PI acos(-1)
using namespace std;

const int N=10;

struct rec{
    double x,y;
};

int n;
int ord[N];
rec bor1,bor2;
rec oil[N];
double r[N];
double tmp,ans=0.0;   // 能覆盖到的最大面积

double min(double d1,double d2,double d3){
    return min(d1,min(d2,d3));
}

double dis(rec r1,rec r2){
    return sqrt((r1.x-r2.x)*(r1.x-r2.x)+(r1.y-r2.y)*(r1.y-r2.y));
}

void calc(int cur,int idx/*第几个*/){
    // 边界
    r[cur]=min(abs(oil[cur].x-bor1.x),abs(oil[cur].x-bor2.x));
    r[cur]=min(r[cur],abs(oil[cur].y-bor1.y),abs(oil[cur].y-bor2.y));
    
    // 其他油滴
    rep(i,1,idx-1){
        if(r[ord[i]]==0.0) continue;
        if(r[ord[i]]>=dis(oil[cur],oil[ord[i]])){
            r[cur]=0.0;
        }else{
            r[cur]=min(r[cur],dis(oil[cur],oil[ord[i]])-r[ord[i]]);
        }
    }
    tmp+=PI*r[cur]*r[cur];
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
    rep(i,1,n) ord[i]=i;
    cin>>bor1.x>>bor1.y>>bor2.x>>bor2.y;
    rep(i,1,n) cin>>oil[i].x>>oil[i].y;

    do{
        tmp=0.0;
        rep(i,1,n) calc(ord[i],i);
        ans=max(ans,tmp);
    }while(next_permutation(ord+1,ord+1+n));
    cout<<(int)round(abs(bor1.x-bor2.x)*abs(bor1.y-bor2.y)-ans);

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

