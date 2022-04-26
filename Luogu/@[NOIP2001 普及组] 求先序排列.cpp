#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int len;

int find(string s,char c){
    for(int i=0;i<s.length();i++)
        if(s[i]==c) return i;
}

void dfs(int l1,int r1,int l2,int r2)
{
    int m=find(s2,s2[r2]);
    cout<<s2[r2];
    if(m>l1) /*具有左子树*/dfs(l1,m-1,l2,r2-r1+m-1);//r1-m为右子树结点数 
    if(m<r1) /*具有右子树*/dfs(m+1,r1,l2+m-l1,r2-1);//m-l1为左子树节点数
}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    // ===================================
    cin>>s1>>s2;
    len=s2.length();
    dfs(0,len-1,0,len-1);

    // ===================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
