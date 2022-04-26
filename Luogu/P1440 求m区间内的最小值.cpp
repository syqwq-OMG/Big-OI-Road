#include <bits/stdc++.h>
#define re register
using namespace std;

const int N=2e6+5;
int n,m;
int a[N];
int head, tail;
int q[N];

void monotoneMin(){
    printf("0\n");
    head=1, tail=0;
    for(int i=1;i<n;i++){
        while(head<=tail && a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        while(head<=tail && q[head]+m<=i) head++;
        printf("%d\n",a[q[head]]);
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(re int i=1;i<=n;i++) scanf("%d",&a[i]);
    monotoneMin();
    return 0;
}