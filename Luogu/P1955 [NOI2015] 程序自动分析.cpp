// 离散化 + 并查集
#include <bits/stdc++.h>
#define re register
using namespace std;

struct node{
    int x;
    int y;
    int op;
};

const int N=1e6+5;
int t;
int n;
node rel[N];    // relation -> 做集合处理
bool flag;

int tot=0;
int book[N*3]; // 离散化
int num;   // 离散化后的个数

int fa[N];

int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y){
    fa[get(x)]=get(y);
}

bool cmp(const node& n1,const node& n2){
    return n1.op>n2.op;
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
    cin>>t;
    while(t--){
        cin>>n;

        // 初始化
        flag=1;
        memset(rel,0,sizeof(rel));
        memset(book,0,sizeof(book));
        memset(fa,0,sizeof(fa));

        // 离散化
        for(re int i=1;i<=n;i++){
            cin>>rel[i].x>>rel[i].y>>rel[i].op;
            book[++tot]=rel[i].x;
            book[++tot]=rel[i].y;
        }
        sort(book+1,book+1+tot);
        num=unique(book+1,book+1+tot)-book-1;
        for(re int i=1;i<=n;i++){
            // 对元素离散化
            rel[i].x=lower_bound(book+1,book+1+num,rel[i].x)-book-1;
            rel[i].y=lower_bound(book+1,book+1+num,rel[i].y)-book-1;
        }
        
        for(re int i=1;i<=num;i++) fa[i]=i;
        sort(rel+1,rel+1+n,cmp);
        for(re int i=1;i<=n;i++){
            int a=get(rel[i].x);
            int b=get(rel[i].y);
            if(rel[i].op){
                if(a!=b) merge(a,b);
            }else{
                if(a==b){
                    flag=0;
                    puts("NO");
                    break;
                }
            }
        }
        if(flag) puts("YES");
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
