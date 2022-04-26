#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=2e6+5;
int n,k;
int a[N];
int head, tail;
int q[N];

void monotoneMax(){
    head=1, tail=0;
    for(re int i=1;i<=n;i++){
        while(head<=tail && a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        while(head<=tail && q[head]+k<=i) head++;
        if(i>=k) cout<<a[q[head]]<<endl;
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
    cin>>n>>k;
    for(re int i=1;i<=n;i++) cin>>a[i];
    monotoneMax();

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
