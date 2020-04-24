#define taskname "UQSEQ"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
int n, m;
lli bit[maxN];

void Enter()
{
    cin >> n >> m;
    fill_n(bit + 1, n, 0);
}

void Increase1(int x, lli Delta)
{
    for (; x > 0; x &= x - 1)
        bit[x] += Delta;
}

lli QueryPoint(int x)
{
    lli res = 0;
    for (; x <= n; x += x & -x)
        res += bit[x];
    return res;
}

void Solve()
{
    for (; m > 0; --m)
    {
        char c;
        int i, j, delta;
        cin >> c;
        if (c == 'I')
            cin >> i >> j >> delta, Increase1(j, delta), Increase1(i - 1, -delta);
        else
            cin >> i, cout << QueryPoint(i) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}
