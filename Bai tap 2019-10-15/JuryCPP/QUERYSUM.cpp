#define taskname "QUERYSUM"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
int n, m, salary[maxN];
lli bit[maxN];

void Enter()
{
    cin >> n >> m;
    fill_n(bit + 1, n, 0);
    fill_n(salary + 1, n, 0);
}

void Increase(int x, int Delta)
{
    for (; x <= n; x += x & -x)
        bit[x] += Delta;
}

lli Query(int x)
{
    lli res = 0;
    for (; x > 0; x &= x - 1)
        res += bit[x];
    return res;
}

void Set(int k, int w)
{
    Increase(k, w - salary[k]);
    salary[k] = w;
}

void Solve()
{
    for (; m > 0; --m)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'S') Set(i, j);
        else cout << Query(j) - Query(i - 1) << '\n';
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
