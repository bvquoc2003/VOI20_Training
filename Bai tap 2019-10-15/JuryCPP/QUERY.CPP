#define taskname "QUERY"
#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 1e5 + 1;
int n, m;
int Max[4 * maxN];

inline int ReadInt()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    int x = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

inline char ReadCmd()
{
    char c;
    while (c = getchar(), c != 'Q' && c != 'S');
    return c;
}

void Init()
{
    int newn = 1;
    while (newn < n) newn *= 2;
    n = newn;
    fill(Max + 1, Max + 2 * n, 0);
}

void Update(int i, int k)
{
    int x = i + n - 1;
    Max[x] = k;
    for (x /= 2; x > 0; x /= 2)
        Max[x] = max(Max[2 * x], Max[2 * x + 1]);
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

inline void Maximize(int& Target, int Value)
{
    if (Value > Target) Target = Value;
}

int Query(int i, int j)
{
    int x = i + n - 1, y = j + n - 1;
    int res = 0;
    while (x <= y)
    {
        if ((x & 1) == 0)
            x >>= 1;
        else
        {
            Maximize(res, Max[x]);
            x = (x >> 1) + 1;
        }
        if ((y & 1) == 0)
        {
            Maximize(res, Max[y]);
            y = (y >> 1) - 1;
        }
        else
            y >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    n = ReadInt();
    m = ReadInt();
    Init();
    while (m-- > 0)
    {
        char cmd = ReadCmd();
        if (cmd == 'S')
        {
            int i = ReadInt();
            int k = ReadInt();
            Update(i, k);
        }
        else
        {
            int i = ReadInt();
            int j = ReadInt();
            WriteInt(Query(i, j));
            putchar('\n');
        }
    }
}
