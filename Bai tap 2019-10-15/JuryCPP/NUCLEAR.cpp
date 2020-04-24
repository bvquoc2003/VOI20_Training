#define taskname "NUCLEAR"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using lli = long long;
const int maxN = 2e5;
const int maxQ = 2e5;

struct TPoint
{
    lli x, y;
    int idx;
};
using PPoint = TPoint*;
int n, q;
TPoint A, B;
TPoint p[maxN + maxQ];
PPoint ptr[maxN + maxQ];
vector<lli> xarr, yarr;
int tree[maxN + 1];
int res[maxQ];

inline int ReadInt()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    int res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void ReadInput()
{
    n = ReadInt();
    for (int i = 0; i < n; ++i)
    {
        p[i].x = ReadInt();
        p[i].y = ReadInt();
        p[i].idx = -1;
    }
    A.x = ReadInt(); A.y = ReadInt();
    B.x = ReadInt(); B.y = ReadInt();
    q = ReadInt();
    for (int i = 0; i < q; ++i)
    {
        p[i + n].x = ReadInt();
        p[i + n].y = ReadInt();
        p[i + n].idx = i;
    }
}

inline lli Sqr(int x)
{
    return (long long) x * x;
}

inline lli Dis2(const TPoint& a, const TPoint& b)
{
    return Sqr(a.x - b.x) + Sqr(a.y - b.y);
}

void Init()
{
    for (int i = 0; i < n; ++i)
    {
        lli newx = Dis2(p[i], A);
        lli newy = Dis2(p[i], B);
        p[i] = {newx, newy, -1};
        xarr.push_back(newx);
        yarr.push_back(newy);
    }
    for (int i = 0; i < q; ++i)
    {
        p[i + n].x = Sqr(p[i + n].x);
        p[i + n].y = Sqr(p[i + n].y);
    }
    sort(xarr.begin(), xarr.end());
    sort(yarr.begin(), yarr.end());
    for (int i = 0; i < n + q; ++i)
        ptr[i] = &p[i];
    sort(ptr, ptr + n + q, [](PPoint a, PPoint b)
    {
        if (a->y != b->y) return a->y < b->y;
        if (a->x != b->x) return a->x < b->x;
        return a->idx < b->idx;
    });
    fill(tree + 1, tree + n + 1, 0);
}

inline void Increase(int x)
{
    for (; x <= n; x += x & -x)
        ++tree[x];
}

inline int Query(int x)
{
    int res = 0;
    for (; x > 0; x &= x - 1)
        res += tree[x];
    return res;
}

void Solve()
{
    for (int i = 0; i < n + q; ++i)
        if (ptr[i]->idx == -1)
        {
            int x = upper_bound(xarr.begin(), xarr.end(), ptr[i]->x) - xarr.begin();
            Increase(x);
        }
        else
        {
            int cx = upper_bound(xarr.begin(), xarr.end(), ptr[i]->x) - xarr.begin();
            int cy = upper_bound(yarr.begin(), yarr.end(), ptr[i]->y) - yarr.begin();
            int cxy = Query(cx);
            res[ptr[i]->idx] = cx + cy - cxy;
        }
}

void Print()
{
    for (int i = 0; i < q; ++i)
    {
        WriteInt(res[i]);
        putchar('\n');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    Solve();
    Print();
}
