#include <bits/stdc++.h>
#define re register
using namespace std;

struct node{
    int a,b;
    int hate;
};

const int N=2e4+5;
const int M=1e5+5;
int n,m;
node a[M];
int fa[N<<1];

bool cmp(node n1,node n2){
    return n1.hate>n2.hate;
}

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
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
    for(re int i=1;i<=(n<<1);i++) fa[i]=i;
    for(re int i=1;i<=m;i++) cin>>a[i].a>>a[i].b>>a[i].hate;
    sort(a+1,a+1+m,cmp);
    for(re int i=1;i<=m;i++){
        int p=get(a[i].a); int q=get(a[i].b);
        if(p==q){
            cout<<a[i].hate; return 0;
        }else{  // 扩展域
            int x_1=a[i].a; int x_2=a[i].a+n;
            int y_1=a[i].b; int y_2=a[i].b+n;
            fa[get(x_2)]=get(y_1);  // merge
            fa[get(y_2)]=get(x_1);
        }
    }
    cout<<0;    // 特判一下...因为
    /*
     * 第一组数据:
     * 2 1
     * 1 2 28135
     * 不特判就啥都不输出了...qwq
    */
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
