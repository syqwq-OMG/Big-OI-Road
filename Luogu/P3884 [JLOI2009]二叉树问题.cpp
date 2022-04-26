#include <bits/stdc++.h>
using namespace std;

struct node{
    int ls,rs,dep,fa;
} tree[105];
int n;
int x,y;
int u,v;
int depth=0,width=0,wid[8];
int k;

// 就自己所在的 node 来更改数值
void dfs(int x){
    if(x){
        tree[x].dep=tree[tree[x].fa].dep+1;
        depth=max(depth,tree[x].dep);
        wid[tree[x].dep]++;
        dfs(tree[x].ls);
        dfs(tree[x].rs);
    }
}

// LCA 最近公共祖先 (BF)
int lca(int x,int y){
    if(x==y) return x;
    if(tree[x].dep==tree[y].dep) return lca(tree[x].fa,tree[y].fa);
    else if(tree[x].dep<tree[y].dep) return lca(x,tree[y].fa);
    else return lca(tree[x].fa,y);
}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ===================================
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        if(tree[x].ls==0) tree[x].ls=y;
        else tree[x].rs=y;
        tree[y].fa=x;
    }
    cin>>u>>v;
    dfs(1);
    cout<<depth<<endl;
    for(int i=1;i<8;i++) width=max(width,wid[i]);
    cout<<width<<endl;
    k=lca(u,v);
    cout<<2*(tree[u].dep-tree[k].dep)+(tree[v].dep-tree[k].dep)<<endl;

    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
