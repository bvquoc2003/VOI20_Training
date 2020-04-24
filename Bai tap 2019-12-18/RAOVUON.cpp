#include <bits/stdc++.h>

using namespace std;;
typedef pair <int, int> point;

point operator - (point a, point b) {
    return point(a.first - b.first, a.second - b.second);
}
bool cmp(point a, point b) { //check counter-clockwise
    return a.first * b.second < a.second * b.first;
}
double dist(point a, point b) {
    return hypot(a.first - b.first, a.second - b.second);
}
int ccw(point a, point o, point b) {
    a = a - o, b = b - o;
    return cmp(a, b);
}

int N, M;
point tree[105], pole[105];

double solve(int start) {
    //let's ignore all poles from 1 -> start-1
    //and choose pole[start] = (x0, y0) as the pole with lowest x-coordinate
    //by doing so, all other trees and poles should lie on the right half plane x >= x0
    for (int i = 1; i <= N; ++i) if (tree[i] <= pole[start]) return 1e9; //cannot cover that tree
    vector <point> sorted_pole; //list of poles, sorted in counter-clockwise order
    for (int i = start; i <= M; ++i) sorted_pole.push_back(pole[i] - pole[start]);
    sort(sorted_pole.begin() + 1, sorted_pole.end(), cmp);
    sorted_pole.push_back(point(0, 0)); //pole[start] itself

    vector <double> dp(sorted_pole.size(), 1e9);
    //dp[i] = minimum cost to construct a convex hull up to pole i,
    //such that all trees lie below the hull
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < i; ++j) if (dp[j] < 1e9) {
            //let's check if connecting j and i fails to 'cover' any tree
            int ok = 1;
            for (int k = 1; k <= N; ++k) if (!ccw(sorted_pole[j], tree[k] - pole[start], sorted_pole[i])) {
                ok = 0;
                break;
            }
            if (ok) dp[i] = min(dp[i], dp[j] + dist(sorted_pole[j], sorted_pole[i]));
        }
    }
    return dp.back();
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> tree[i].first >> tree[i].second;
    cin >> M;
    for (int i = 1; i <= M; ++i) cin >> pole[i].first >> pole[i].second;
    sort(pole + 1, pole + M + 1);
    if (N == 0) return cout << "0.00" << endl, 0;
    double ans = 1e9;
    for (int i = 1; i < M; ++i) ans = min(ans, solve(i));
    cout << setprecision(2) << fixed << ans << endl;
}
