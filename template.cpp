#include <bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i=a;i<=b;i++)
#define per(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;

template<typename T>
void read(T& _x){
    T _num=0,_sign=1;char _ch=getchar();
    while(_ch<'0'||_ch>'9'){if(_ch=='-')_sign=-1;_ch=getchar();}
    while(_ch>='0'&&_ch<='9'){_num=_num*10+_ch-'0';_ch=getchar();}
    _x=_num*_sign;
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
    

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

