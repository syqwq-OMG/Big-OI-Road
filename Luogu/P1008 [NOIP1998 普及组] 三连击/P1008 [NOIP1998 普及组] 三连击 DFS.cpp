#include <bits/stdc++.h>
#define re register
using namespace std;

int a[15];
bitset<10> vis;
int x,y,z;

int make_int(int a,int b,int c){
    return 100*a+10*b+c;
}

void dfs(int k){
    if(k==10){
        x=make_int(a[1],a[2],a[3]);
        y=make_int(a[4],a[5],a[6]);
        z=make_int(a[7],a[8],a[9]);
        if((double)y/x==2 && (double)z/x==3)
            cout<<x<<" "<<y<<" "<<z<<endl;
        return;
    }
    for(re int i=1;i<=9;i++){
        if(vis[i]) continue;
        a[k]=i;
        vis[i]=1;
        dfs(k+1);
        vis[i]=0;
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
    dfs(1);
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
