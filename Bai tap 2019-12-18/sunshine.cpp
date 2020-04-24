#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define x first
#define y second

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <ll, ll> pt;
typedef pair <pt, int> data;

int N;
vector <pt> b;
vi Left, Right;
pt O;

void operator -= (pt &a, pt b) { a.x -= b.x; a.y -= b.y; }
bool ccw(pt a, pt b, pt c) { a -= c, b -= c; return a.x * b.y > a.y * b.x; }
//kiem tra doan thang ab co cat diem c hay khong bang tich co huong

void build(vi &ans, bool zz) {
    vector <data> a(N + 2, data());
    if (!zz) ff(i, 1, N) a[i] = data(b[i], i);
    else ff(i, 1, N) a[i] = data(b[i], N + 1 - i);
    O = a[1].x;
    ans[a[1].y] = -1;
    int ptr = 2;
    ff(i, 2, N) {
        while (ptr > 2 && ccw(a[ptr-1].x, a[i].x, a[ptr-2].x) != zz) --ptr; //xoa a[ptr-1] khoi stack
        if (a[ptr-1].x.y < a[i].x.y) ans[a[i].y] = -1; else ans[a[i].y] = a[ptr-1].y;
        a[ptr++] = a[i];
    }
}

ll dist(pt p, pt q) { return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); }
bool check(int i, int j, int k) { return dist(b[i], b[k]) + dist(b[j], b[k]) <= dist(b[i], b[j]); }
//kiem tra goc A_i A_k A_i tu

int main(void) {
    freopen("sunshine.inp", "r", stdin);
    freopen("sunshine.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    b.assign(N + 2, pt());
    ff(i, 1, N) cin >> b[i].x >> b[i].y;
    Left.assign(N + 1, 0); Right.assign(N + 1, 0);
    build(Left, 0);
    reverse(b.begin(), b.end());
    build(Right, 1);
    reverse(b.begin(), b.end());
    int ans = 0;
    ff(i, 1, N) if (Left[i] < 0 || Right[i] < 0 || check(Left[i], Right[i], i)) ++ans;
    cout << ans << endl;
    return 0;
}
