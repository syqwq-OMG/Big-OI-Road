#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N=1e4+5;
const int base=13331;
int n;
int a[N];
string tmp;
int ans=1;

ull Hash(string s){
    ull ans=0, p=1;
    for(int i=0;i<s.size()-1;i++,p*=base){
        ans+=(ull)s[i]*p*1ll;
    }
    return ans;
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
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a[i]=Hash(tmp);
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]) ans++;
    }
    cout<<ans<<endl;

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
