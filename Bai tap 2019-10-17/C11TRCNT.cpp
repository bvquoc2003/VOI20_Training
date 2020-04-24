#include <bits/stdc++.h>
#define task "C11TRCNT"
using namespace std;
const int MaxN=205;
struct Diem {int64_t x,y;} a[MaxN];
int n, cs=0;
int64_t Res=0;
void Nhap() {
    freopen("C11TRCNT.INP","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
}
bool Tamgiac(Diem a, Diem b, Diem c) { //Ap dung ham CCW. Neu k khac 0 thi 3 diem tao thanh 1 tam giac
    int64_t k=((b.x-a.x)*(c.y-b.y))-((b.y-a.y)*(c.x-b.x));
    if (k!=0) return true;
    else return false;
}
void Xuli() {
    int64_t d[MaxN], Min=INT_MAX;
    memset(d,0,sizeof(d));
    for (int i=1;i<=n-2;i++)
    for (int j=i+1;j<=n-1;j++)
    for (int k=j+1;k<=n;k++)
    if (Tamgiac(a[i],a[j],a[k])) {
        Res++;
        d[i]++; d[j]++; d[k]++;
    }
    for (int i=1;i<=n;i++)
    if (d[i]<Min) {
        Min=d[i];
        cs=i;
    }
}
void Xuat() {
    freopen("C11TRCNT.OUT","w",stdout);
    cout<<Res<<" "<<cs;
}
int32_t main(void) {
    Nhap();
    Xuli();
    Xuat();
    return 0;
}