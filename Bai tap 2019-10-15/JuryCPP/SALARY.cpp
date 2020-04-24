/*
#DFS, #tree decomposition, #segment trees, #binary indexed trees
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long lli;
typedef vector<int> TAdj;
const int maxN = 1e5 + 1;

int n, m;
lli salary[maxN], bit[maxN];
TAdj adj[maxN];
int L[maxN], R[maxN];

void Enter() {
    cin >> n >> m;
    cin >> salary[1];
    for (int i = 2; i <= n; ++i) {
        int j;
        cin >> salary[i] >> j;
        adj[j].push_back(i);
    }
}

int Time = 0;

void Visit(int u) {
    L[u] = ++Time;
    for (int v: adj[u]) Visit(v);
    R[u] = Time;
}

void Init() {
    fill_n(bit + 1, n, 0);
    Visit(1);
}

void Increase(int x, lli Delta) {
    for (; x > 0; x &= x - 1)
        bit[x] += Delta;
}

lli Query(int x) {
    lli res = salary[x];
    for (x = L[x]; x <= n; x += x & -x)
        res += bit[x];
    return res;
}

void Solve() {
    for (; m > 0; --m) {
        char cmd;
        int u, x;
        cin >> cmd;
        if (cmd == 'p') {
            cin >> u >> x;
            Increase(R[u], x);
            Increase(L[u], -x);
        } else {
            cin >> u;
            cout << Query(u) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SALARY.INP", "r", stdin);
    freopen("SALARY.OUT", "w", stdout);
    Enter();
    Init();
    Solve();
}
