#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
typedef long long ll;

const int N=22;

int n;
int seq[N];
vector<pair<int,int> > a,b;    // 左右两个集合 sum+state
bool used[1<<N];
ll ans=0;
int p1,p2;

template<typename T>
void read(T& _x){
    T _num=0,_sign=1;char _ch=getchar();
    while(_ch<'0'||_ch>'9'){if(_ch=='-')_sign=-1;_ch=getchar();}
    while(_ch>='0'&&_ch<='9'){_num=_num*10+_ch-'0';_ch=getchar();}
    _x=_num*_sign;
}

void dfs(int l,int r,int sum,int state,int idx){
    if(l>r){
        if(idx){
            b.push_back(make_pair(sum,state));
            return;
        }else{
            a.push_back(make_pair(sum,state));
            return;
        }
    }
    // 针对 seq[l]
    dfs(l+1,r,sum,state,idx);
    dfs(l+1,r,sum-seq[l],state|(1<<(l-1)),idx);   // l 从1开始
    dfs(l+1,r,sum+seq[l],state|(1<<(l-1)),idx);
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
    read(n);
    rep(i,1,n) read(seq[i]);

    int mid=n>>1;
    dfs(1,mid,0,0,0);
    dfs(mid+1,n,0,0,1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // for(auto x:a){cout<<x.first<<" "<<x.second<<endl;}
    // cout<<"===============\n";
    // for(auto x:b){cout<<x.first<<" "<<x.second<<endl;}

    p1=0, p2=b.size()-1;
    while(p1<a.size() && p2>=0){
        while(a[p1].first+b[p2].first>0 && p2>=0) p2--;
        int sig=p2; // 小优化: 相同的话就不用跳了
        while(p2>=0 && a[p1].first+b[p2].first==0){
            if(!used[a[p1].second|b[p2].second]){ // 状态没有重复
                used[a[p1].second|b[p2].second]=1;
                ans++;
            }
            p2--;
        }
        if(p1+1<a.size() && a[p1].first==a[p1+1].first) p2=sig;
        p1++;
    }
    cout<<ans-1;
// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

