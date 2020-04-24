#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef pair<ll, ll> ii;

const int maxn = (int) 1e5 + 5;
const int mod = (int) 1e9 + 7;
const int inf = (int) 2e9;
const int base = 343;
const double eps = 1e-9;
#define fi first
#define se second
#define rep(i, a, b) for (int i = a; i < b; i ++)
#define per(i, a, b) for (int i = b - 1; i >= a; i --)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), x.end()
#define SZ(x) ((int)x.size())


struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (const point& p) const {
        if(fabs(x - p.x) < eps) {
            if(fabs(y - p.y) < eps) return 0;
            else return y < p.y;
        }
        else return x < p.x;
    }
};
struct line {
    int a, b, c;
    line() {}
    line(int a, int b, int c) : a(a), b(b), c(c) {}
};
line get(point p, point q) {
    int a = p.x - q.x;
    int b = p.y - q.y;
    int x = p.x, y = p.y;
    swap(a, b);
    if(a < 0) a = -a;
    else b = -b;
    return line(a, b, a * -x + b * -y);
}
bool bug;
point cut(line d, line e) {
    point res;
    res = point(0, 0);
    double x, y;
    if(d.a == 0 && e.a == 0) return res;
    if(d.b == 0 && e.b == 0) return res;
    if(d.a * e.b != 0 && d.b * e.a != 0) {
        if(d.a * e.b == d.b * e.a) return res;
        res.x = -1.0 * (e.c * d.b - d.c * e.b) / (e.a * d.b - d.a * e.b);
        res.y = -1.0 * (e.c * d.a - d.c * e.a) / (e.b * d.a - d.b * e.a);
        return res;
    }
    else {
        if(d.a == 0) {
            y = -d.c * 1.0 / d.b;
            x = -1.0 * (e.b * y + e.c) / e.a;
        }
        else if(d.b == 0) {
            x = -1.0 * d.c / d.a;
            y = -1.0 * (e.a * x + e.c) / e.b;
        }
        else if(e.a == 0) {
            y = -1.0 * e.c / e.b;
            x = -1.0 * (d.b * y + d.c) / d.a;
        }
        else if(e.b == 0) {
            x = -1.0 * e.c / e.a;
            y = -1.0 * (d.a * x + d.c) / d.b;
        }
        res = point(x, y);
        ///if(bug) cout << x << ' ' << y << endl;
        return res;
    }
}
int n, k, res;
point a[maxn];
line L[maxn];
set<point> S;

bool inside(point p) {
    return !(p.x <= a[1].x || p.y <= a[1].y || p.x >= a[2 * n + 1].x || p.y >= a[2 * n + 1].y);
}

void print(point p) {
    cout << fixed << setprecision(2) << p.x << ' ' << p.y << endl;
}

void print(line l) {
    cout << l.a << "x + " << l.b << "y + " << l.c << " = 0\n";
}

int main() {
    freopen("squarepart.inp", "r", stdin);
    freopen("squarepart.out", "w", stdout);

    scanf("%d %d", &n, &k);
    a[1] = point(1.0, 1.0);
    rep(i, 2, n + 2) a[i] = a[i - 1], a[i].x ++;
    rep(i, n + 2, 2 * n + 2) a[i] = a[i - 1], a[i].y ++;
    rep(i, 2 * n + 2, 3 * n + 2) a[i] = a[i - 1], a[i].x --;
    rep(i, 3 * n + 2, 4 * n + 2) a[i] = a[i - 1], a[i].y --;
    res = 1;

    rep(i, 0, k) {
        int x, y; scanf("%d %d", &x, &y);
        L[i] = get(a[x], a[y]);
        S.clear();
        int cur = SZ(S);
        rep(j, 0, i) {
            point p = cut(L[i], L[j]);
            if(inside(p)) S.insert(p);
        }
        cur = SZ(S) - cur + 1;
        res += cur;
    }
    cout << res << endl;
    return 0;
}
