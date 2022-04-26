#include <bits/stdc++.h>
using namespace std;

struct node{
    char val;
    int ls,rs,prevv;
} tree[30];
int n;
int root;

// 先序遍历
void preorder(int x){
    if(x){
        cout<<tree[x].val;
        preorder(tree[x].ls);
        preorder(tree[x].rs);
    }
}

int find_root(){
    for(int i=1;i<=26;i++)
        if(tree[i].prevv==0) return i;
    return 1;
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
    for(int i=1;i<=n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        tree[a-'a'+1].val=a;
        tree[a-'a'+1].ls=(b=='*')?0:b-'a'+1;
        tree[a-'a'+1].rs=(c=='*')?0:c-'a'+1;
        tree[tree[a-'a'+1].ls].prevv=a-'a'+1;
        tree[tree[a-'a'+1].rs].prevv=a-'a'+1;
    }
    root=find_root();
    preorder(root);

    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
