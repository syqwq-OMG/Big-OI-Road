// 踹树 + edge 神犇 mua
#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;

const int N=1e3+5;
const int M=1e6+5;
const int MAXN=1e6+5;
const int root=0;

int n,m,l;
int sz=0, trie[MAXN][26];
int tot=0;
vector<int> val[M]; //! MLE
string tmp;

void add(const string& str,const int& para){
    int ch,p=root;
    for(re int i=0;i<str.size();i++){
        ch=str[i]-'a';
        if(!trie[p][ch]) trie[p][ch]=++sz;
        p=trie[p][ch];
    }
    val[p].push_back(para);
}

void query(const string& str){
    int ch,p=root;
    for(re int i=0;i<str.size();i++){
        ch=str[i]-'a';
        if(!trie[p][ch]){
            cout<<endl;
            return;
        }
        p=trie[p][ch];
    }
    sort(val[p].begin(),val[p].end());  // !!!!!! 去重 !!!!!! %%%%%%%%%%%%
    int x=unique(val[p].begin(),val[p].end())-val[p].begin();
    for(re int i=0;i<x;i++) cout<<val[p][i]<<" ";
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ======================================================================
    cin>>n;
    for(re int i=1;i<=n;i++){
        cin>>l;
        while(l--){
            cin>>tmp;
            add(tmp,i);
        }
    }
    cin>>m;
    while(m--){
        cin>>tmp;
        query(tmp);
    }

    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
