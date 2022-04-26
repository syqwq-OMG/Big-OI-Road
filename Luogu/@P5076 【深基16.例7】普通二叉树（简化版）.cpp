#include <bits/stdc++.h>
using namespace std;

struct node{
    int ls,rs,size,cnt,val;
} tree[500005];
int cont=0;

/*插入节点*/
void add(int x,int v){
    tree[x].size++;
    if(tree[x].val==v){
        tree[x].cnt++;
        return;
    }
    if(tree[x].val>v){
        if(tree[x].ls!=0) add(tree[x].ls,v);
        else{
            cont++;
            tree[x].ls=cont;
            tree[cont].val=v;
            tree[cont].size=tree[cont].cnt=1;
        }
    }else{
        if(tree[x].rs!=0) add(tree[x].rs,v);
        else{
            cont++;
            tree[x].rs=cont;
            tree[cont].val=v;
            tree[cont].size=tree[cont].cnt=1;
        }
    }
}

/*找前驱*/
int query_fr(int x,int v,int ans){
    
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


    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
