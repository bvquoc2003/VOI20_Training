// https://vn.spoj.com/problems/MAXARR1/
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector <int> a(100005,0);
size_t N=100000;
int32_t main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    a[1]=1;
    for (size_t i=2;i<=N;i++) {
        if (i&1) a[i]=a[i>>1]+a[(i>>1)+1]; // (i&1) --> true nếu i lẻ
        else a[i]=a[i>>1]; 
    }
    for (int i=1;i<=N;i++) a[i]=max(a[i-1],a[i]);
    int T, n; cin>>T;
    while (T--) {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}