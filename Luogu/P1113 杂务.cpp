#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int n;
vector<int> head[N];
int in[N];
int len[N];
queue<int> q;
int f[N];
int ans=0;

// x --> y
void add(int x,int y){
    head[x].push_back(y);
    in[y]++;
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
    for(int i=0;i<n;i++){
        int u,t,v=1;
        cin>>u>>t; len[u]=t;
        while(true){
            cin>>v;
            if(!v) break;
            add(v,u);   //! 注意加边方向
        }
    }

    // topsort
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);
        f[i]=len[i];
    }
    while(!q.empty()){    
        int x=q.front(); q.pop();
        for(int i=0;i<head[x].size();i++){
            int y=head[x][i];
            if(--in[y]==0) q.push(y);
            f[y]=max(f[y],f[x]+len[y]); //! DP
        }
    }

    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}