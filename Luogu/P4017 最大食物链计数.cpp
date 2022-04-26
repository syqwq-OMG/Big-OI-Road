#include <bits/stdc++.h>
#define re register // 卡常 doge
using namespace std;

const int MAXN = 5005;
const int p = 80112002;
int n, m;
vector<int> head[MAXN];
int in[MAXN], out[MAXN];
int u, v;
queue<int> q;
int w[MAXN]; // way
int ans = 0;

// 加边
void add(int x, int y)
{
    head[x].push_back(y);
    out[x]++, in[y]++;
}

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    // ======================================================================
    cin >> n >> m;
    for (re int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add(u, v);
    }

    // topsort
    for (re int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            w[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (re int i = 0; i < head[x].size(); i++)
        {
            int y = head[x][i];
            --in[y];
            w[y] = (w[y] + w[x]) % p;
            if (!in[y])
                q.push(y);
        }
    }

    for (re int i = 1; i <= n; i++)
        if (!out[i])
        {
            //! cout<<w[i]%p<<endl;
            //! 食物链的末端可能不止一个节点
            ans = (ans + w[i]) % p;
        }
    cout << ans << endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
