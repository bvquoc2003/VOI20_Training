#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
#define ll long long 
const ll nMax = 100050;

ll n, k;
ll a[nMax];
deque <ll> d;
ll l[nMax], r[nMax];

void push(ll x) {
    while (!d.empty() && a[x] >= a[d.back()]) d.pop_back();
    d.push_back(x);
}

void search_left() {
    ll i = d.size() - 2;
    while (a[d[i]] <= a[d.back()] + k) i--;
    l[d.back()] = d[i] + 1;
}

void search_right() {
    ll i = d.size() - 2;
    while (a[d[i]] <= a[d.back()] + k) i--;
    r[d.back()] = d[i] - 1;
}


int main()
{
    freopen("naughty.inp", "r", stdin);
    freopen("naughty.out", "w", stdout);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = INT_MAX;

    push(0);
    for (ll i = 1; i <= n; i++){
        push(i);
        search_left();
    }

    push(n+1);
    for (ll i = n; i > 0; i--) {
        push(i);
        search_right();
    }

    for (ll i = 1; i <= n; i++) 
        cout << r[i] - l[i] + 1 << " ";


    return 0;
}