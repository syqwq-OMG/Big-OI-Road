#include <bits/stdc++.h>
#define re register
// #define luogu
using namespace std;

const int N=10;
string st,en;
int n=1;
string a[N],b[N];
int ans=0;

int step=0;
string s,tmp;
queue<string> qst,qen;	// 记录状态
map<string,int> mst,men;	// 记录步数 

// 双向 BFS
int bfs(){
    qst.push(st); mst[st]=0;
    qen.push(en); men[en]=0;
    while(++step<=5){	// 一共10步， 两边各扩展5步
        // 扩展st
        while(mst[qst.front()]==step-1){	// 在上一层, 保证 st, en 各扩展一次 
            s=qst.front(); qst.pop();
            for(re int i=1;i<=n;i++){
                int pos=0;
                // 找到所有 s 中的 a[i] 
                while(pos<s.length()){
                    if(s.find(a[i],pos)==s.npos) break;
                    tmp=s;
                    tmp.replace(s.find(a[i],pos),a[i].length(),b[i]);

                    if(men.find(tmp)!=men.end()) return (step<<1)-1;
                    if(mst.find(tmp)!=mst.end()) {pos++; continue;}
                    qst.push(tmp); mst[tmp]=step;

                    pos++;
                }
            }
        }

        // 扩展 en
        while(men[qen.front()]==step-1){
            s=qen.front(); qen.pop();
            for(re int i=1;i<=n;i++){
                int pos=0;
                while(pos<s.length()){
                    if(s.find(b[i],pos)==s.npos) break;
                    tmp=s;
                    tmp.replace(s.find(b[i],pos),b[i].length(),a[i]);

                    if(mst.find(tmp)!=mst.end()) return step<<1;
                    if(men.find(tmp)!=men.end()) {pos++; continue;}
                    qen.push(tmp); men[tmp]=step;

                    pos++;
                }
            } 

        } 
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
#ifndef luogu
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
// ===================================================
    cin>>st>>en;
    while(cin>>a[n]>>b[n]) n++; n--;
    
    ans=bfs();
    if(ans==-1) puts("NO ANSWER!");
    else cout<<ans<<endl;

// ===================================================
    return 0;
}