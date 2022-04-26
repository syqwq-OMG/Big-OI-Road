#include <bits/stdc++.h>
#define re register
#define gc getchar
using namespace std;

struct Edge{
	int to;
	int nxt;
	int val;
};

const int N=5e4+5,M=5e4+5;
int n,m;
int t;
int deg1=0;
int army[M];

int tot=0;
int head[N];
Edge edge[N<<1];

int l=1,r;

queue<int> q;
int dep[N];
int dis[N];

inline int read(){
	int sign=1,num=0;
	char ch=gc();
	while(ch<'0'||ch>'9') {
		if(ch=='-') sign=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=gc();
	}
	return sign*num;
}

void add(int x,int y,int z){
	edge[++tot].val=z;
	edge[tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
	
	if(x==1) deg1++;
}

void bfs(){
	dep[1]=1;dis[1]=0;q.push(1);
	while(q.size()){
		int x=q.front(); q.pop();	
		for(re int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].to;
			if(dep[y]) continue;
			dep[y]=dep[x]+1;
			dis[y]=dis[x]+edge[i].val;
			q.push(y);
		}
	}
	
}

bool valid(int x){
	
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
	n=read();
	t=(int)(log(n)/log(2))+1;
	for(re int i=1;i<n;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
		r+=w;
	}
	m=read();
	if(deg1>m){
		puts("-1");
		goto end;
	}
	for(re int i=1;i<=m;i++) army[i]=read();
	
	bfs();
	while(l<=r){
		int mid=(l+r)>>1;
		if(valid(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;

// ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}

