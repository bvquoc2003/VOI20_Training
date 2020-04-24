/*
#binary indexed trees, #segment trees
*/
#define taskname "JOSEPHUS"
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 1e5 + 1;
int n, m;
int bit[maxN];

void ReadInput()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        bit[i] = i & -i;
}

inline int Locate(int p)
{
    int x = 0, len = 1;
    while (len * 2 <= n) len *= 2;
    for (; len > 0; len /= 2)
    {
        int y = x + len;
        if (y <= n && bit[y] < p)
        {
            x = y;
            p -= bit[y];
        }
    }
    return x + 1;
}

inline void Decrease(int x)
{
    for (; x <= n; x += x & -x)
        --bit[x];
}

void Solve()
{
    int p = 1;
    for (int k = n; k > 0; --k)
    {
        p = (p + m - 2) % k + 1;
        int i = Locate(p);
        cout << i << ' ';
        Decrease(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    ReadInput();
    Solve();
}
