#include <bits/stdc++.h>
#define re register
using namespace std;

const int N = 1e3 + 5;
int n;
int p1[N], p2[N];

int f[N][N];

int main()
{
    ios::sync_with_stdio(0);
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    // ======================================================================
    cin >> n;
    for (re int i = 1; i <= n; i++)
        cin >> p1[i];
    for (re int i = 1; i <= n; i++)
        cin >> p2[i];
    for (re int i = 1; i <= n; i++) // p1
        for (re int j = 1; j <= n; j++) // p2
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (p1[i] == p2[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][n] << endl;
    // ======================================================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
