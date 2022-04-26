//? 反向加边 + DFS
/**
  //? 按题目来每次考虑每个点可以到达点编号最大的点，不如考虑较大的点可以反向到达哪些点

  //? 循环从N到1，则每个点i能访问到的结点的A值都是i

  //? 每个点访问一次，这个A值就是最优的，因为之后如果再访问到这个结点那么答案肯定没当前大了
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,m;
int u,v;
vector<int> head[MAXN];
////bitset<MAXN> vis;
int ans[MAXN];

// 加边
void add(int x,int y){
    head[x].push_back(y);
}

void dfs(int k,int n){
    if(!ans[k]) ans[k]=n;
    for(int i=0;i<head[k].size();i++){
        int y=head[k][i];
        if(ans[y]) continue;
        //ans[y]=n;
        dfs(y,n);
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
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>u>>v;
        add(v,u);   //! 反向加边
    }
    for(int i=n;i>=1;i--) dfs(i,i);    
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
