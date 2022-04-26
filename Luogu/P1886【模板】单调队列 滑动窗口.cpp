#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=1e6+5;
int n,k;
int q[N];   // 存储元素索引, 方便判断出队
int head,tail;
int a[N];

void monotoneMin(){
    // memset(q,0,sizeof(q));
    head=1, tail=0;
    for(re int i=1;i<=n;i++){
        while(head<=tail && a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        while(head<=tail && q[head]+k<=i) head++;
        if(i>=k) cout<<a[q[head]]<<" ";
    }
    cout<<endl;
}

void monotoneMax(){
    // memset(q,0,sizeof(q));
    head=1, tail=0;
    for(re int i=1;i<=n;i++){
        while(head<=tail && a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        while(head<=tail && q[head]+k<=i) head++;
        if(i>=k) cout<<a[q[head]]<<" ";
    }
    cout<<endl;
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
    cin>>n>>k;
    for(re int i=1;i<=n;i++) cin>>a[i];
    monotoneMin();
    monotoneMax();
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
