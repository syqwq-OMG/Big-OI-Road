#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e6+5;
const int M=2e3+5;
int n,m;
int a[N];
int b[M];   // 用来记录画家次数
int cnt=0;  // 记录区间有几位不同画家

int l,r;    // 左指针和右指针
int len=0x3f3f3f3f;    // 区间长度
int ansl,ansr;  // 答案

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
    for(re int i=1;i<=n;i++) cin>>a[i];
    l=r=1; b[a[1]]=1; cnt++;
    while(l<=r && r<=n){
        if(cnt==m){
            if(len>r-l+1){
                len=r-l+1;
                ansl=l, ansr=r;
            }
            // 满了就把左边扔掉
            if(--b[a[l]]==0) cnt--;
            l++;
        }else{
            // 没满就加右边
            r++;
            if(++b[a[r]]==1) cnt++;
        }
    }
    cout<<ansl<<" "<<ansr;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
