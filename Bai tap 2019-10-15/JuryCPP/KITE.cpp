#define taskname "KITE"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1e5 + 1;
int n, a[maxN], id[maxN], res[maxN];
int bit[maxN];

void Enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j)
         {
             return (a[i] > a[j]) || (a[i] == a[j] && i > j);
         });
    fill_n(bit + 1, n, 0);
}

void Increase(int x)
{
    for (; x <= n; x += x & -x)
        ++bit[x];
}

int Query(int x)
{
    int res = 0;
    for (; x > 0; x &= x - 1)
        res += bit[x];
    return res;
}

void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        int j = id[i];
        res[j] = Query(j - 1) + 1;
        Increase(j);
    }
}

void Print()
{
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
    Print();
}
