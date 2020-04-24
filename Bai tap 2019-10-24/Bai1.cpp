#include <bits/stdc++.h>
#define MaxN 1000001
using namespace std;
int n;
int64_t a[MaxN], f[MaxN], l[MaxN];
int64_t Max(int64_t a, int64_t b, int64_t c) {
    int64_t MAX=a;
    MAX=max(b,MAX);
    MAX=max(c,MAX);
    return MAX;
}
void Nhap() {
    freopen("input.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void QHD() {
    f[0]=0;f[1]=a[1]; f[2]=a[1]+a[2];
    for (int i=3;i<=n;i++) f[i]=Max(f[i-1],f[i-2]+a[i],f[i-3]+a[i-1]+a[i]);
}
void Xuat() {
    freopen("output.txt","w",stdout);
    cout<<f[n];
}
int main() {
    Nhap();
    QHD();
    Xuat();
    return 0;
}
