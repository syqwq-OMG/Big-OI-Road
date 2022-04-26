#include <bits/stdc++.h>
#define re register
using namespace std;

int a[9]={1,2,3,4,5,6,7,8,9};
int x,y,z;

int make_int(int a,int b,int c){
    return 100*a+10*b+c;
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
    while(next_permutation(a,a+9)){
        x=make_int(a[0],a[1],a[2]);
        y=make_int(a[3],a[4],a[5]);
        z=make_int(a[6],a[7],a[8]);
        if((double)y/x==2 && (double)z/x==3)
            cout<<x<<" "<<y<<" "<<z<<endl;
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
