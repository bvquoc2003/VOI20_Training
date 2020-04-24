#define taskname "FLIP"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 2e5 + 1;
const int maxM = 2e5 + 1;
using TArrayN = int[maxN];
using TArrayM = int[maxM];
using TArray4M = int[4 * maxM];
int n, m;
TArrayN a, b, invalid, idn, aidx, bidx;
TArrayM c, sortedc, idm, sortmap, leaf;
bool flip[maxN];

TArray4M L, H, f;

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}

void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

inline void Maximize(int& Target, int Value)
{
    if (Target < Value)
        Target = Value;
}

void ReadInput()
{
    n = ReadInt();
    m = ReadInt();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = ReadInt();
        b[i] = ReadInt();
    }
    for (int i = 1; i <= m; ++i)
        c[i] = ReadInt();
}

void PrepareIndexes()
{
    iota(idm + 1, idm + m + 1, 1);
    sort(idm + 1, idm + m + 1, [](int i, int j)
    {
        return c[i] < c[j];
    });
    for (int i = 1; i <= m; ++i)
    {
        sortedc[i] = c[idm[i]];
        sortmap[idm[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        aidx[i] = lower_bound(sortedc + 1, sortedc + m + 1, min(a[i], b[i])) - sortedc;
        bidx[i] = lower_bound(sortedc + 1, sortedc + m + 1, max(a[i], b[i])) - sortedc;
    }
}

void Build(int x, int low, int high)
{
    L[x] = low;
    H[x] = high;
    if (low == high)
    {
        f[x] = idm[low];
        leaf[low] = x;
    }
    else
    {
        int mid = (low + high) / 2;
        Build(x * 2, low, mid);
        Build(x * 2 + 1, mid + 1, high);
        f[x] = max(f[x * 2], f[x * 2 + 1]);
    }
}

inline int Query(int i, int j)
{
    if (i > j)
        return 0;
    int x = leaf[i];
    int res = f[x];
    for (; x > 1; x /= 2)
    {
        if (H[x] > j)
            break;
        if (x % 2 == 0 && H[x + 1] <= j)
            Maximize(res, f[x + 1]);
    }
    x = leaf[j];
    Maximize(res, f[x]);
    for (; x > 1; x /= 2)
    {
        if (L[x] < i)
            break;
        if (x % 2 == 1 && L[x - 1] >= i)
            Maximize(res, f[x - 1]);
    }
    return res;
}

void Phase1()
{
    Build(1, 1, m);
    for (int k = 1; k <= n; ++k)
        invalid[k] = Query(aidx[k], bidx[k] - 1);
}

inline void Increase(int x)
{
    for (; x <= m; x += x & -x)
        ++f[x];
}

inline int Count(int x)
{
    int res = 0;
    for (; x > 0; x &= x - 1)
        res += f[x];
    return res;
}

void Phase2()
{
    iota(idn + 1, idn + n + 1, 1);
    sort(idn + 1, idn + n + 1, [](int i, int j)
    {
        return invalid[i] < invalid[j];
    });
    fill(f + 1, f + m + 1, 0);
    int k = n;
    for (int ic = m; ic >= 0; --ic)
    {
        while (ic == invalid[idn[k]])
        {
            int coin = idn[k];
            int nflips = m - ic - Count(bidx[coin] - 1);
            flip[coin] = nflips % 2 == 1;
            --k;
            if (k == 0)
                break;
        }
        if (ic == 0 || k == 0)
            break;
        Increase(sortmap[ic]);
    }
}

void Print()
{
    for (int i = 1; i <= n; ++i)
        if (invalid[i] > 0 && a[i] < b[i])
            swap(a[i], b[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (flip[i])
            WriteInt(b[i]);
        else
            WriteInt(a[i]);
        putchar(' ');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    PrepareIndexes();
    Phase1();
    Phase2();
    Print();
}
