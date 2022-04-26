#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e5+5;
int n=0;
int tmp;
int h[N];

int lena=0;
int a[N];

int lenb=0;
int b[N];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    while(cin>>tmp) h[++n]=tmp;
    for(re int i=1;i<=n;i++){
        // 最长不上升子序列 O(nlog(n))
        if(h[i]<=a[lena] || lena==0) a[++lena]=h[i];
        else{
            int p=upper_bound(a+1,a+1+lena,h[i],greater<int>())-a;  // 相等元素可以留在序列里, 不用被踢走
            a[p]=h[i];
        }
        // 最长上升子序列
        if(h[i]>b[lenb] || lenb==0) b[++lenb]=h[i];
        else{
            int p=lower_bound(b+1,b+1+lenb,h[i])-b; // 相同元素不能算, 因为可以合并到一堆里面去
            b[p]=h[i];
        }
    }
    cout<<lena<<endl;
    cout<<lenb<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
