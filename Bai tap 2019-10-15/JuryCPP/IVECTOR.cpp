#define taskname "IVECTOR"
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 1e5 + 1;
int n, bit[maxN];
int x[maxN], t[maxN], pos[maxN];

void Enter()
{
    cin >> n;
}

void Decrease(int x)
{
    for (; x <= n; x += x & -x) --bit[x];
}

int Query(int x)
{
    int res = 0;
    for (; x > 0; x &= x - 1)
        res += bit[x];
    return res;
}

int Find(int t)
{
    int x = 0;
    int p = 1;
    while (p << 1 <= n) p <<= 1;
    for (; p > 0; p >>= 1)
    {
        int y = x + p;
        if (y <= n && bit[y] <= t)
            x = y, t -= bit[y];
    }
    return x;
}

void Solve1()
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
        pos[x[i]] = i;
    }
    for (int x = 1; x <= n; ++x) bit[x] = x & -x;
    for (int i = 1; i <= n; ++i)
    {
        int j = pos[i];
        t[i] = Query(j - 1);
        Decrease(j);
    }
    for (int i = 1; i <= n; ++i) cout << t[i] << ' ';
    cout << '\n';
}

void Solve2()
{
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int x = 1; x <= n; ++x) bit[x] = x & -x;
    for (int i = 1; i <= n; ++i)
    {
        int j = Find(t[i]);
        x[j + 1] = i;
        Decrease(j + 1);
    }
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve1();
    Solve2();
}
