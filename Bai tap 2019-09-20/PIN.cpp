#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct paper {
    int x1, y1, x2, y2;
    paper() {x1=0; y1=0; x2=0; y2=0;}
    paper(int X1, int Y1, int X2, int Y2) {x1=X1; y1=Y1; x2=X2; y2=Y2;}
};
int n, res=0;
vector <paper> a;
void Nhap() {
    freopen("PIN.INP","r",stdin);
    cin>>n; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
}
bool Check(paper a, paper b) {return (b.x1 < a.x2 && b.x2 > a.x1 && b.y1 < a.y2 && b.y2 > a.y1);}
void Brute_Force() {
    for (int i=1;i<n;i++)
    for (int j=i+1;j<=n;j++) 
    if (Check(a[i],a[j])) res++;
}
void Xuat() {
    freopen("PIN.OUT","w",stdout);
    cout<<res;
} 
int32_t main(void) {
    FastIO;
    Nhap();
    Brute_Force();
    Xuat();
    return 0;
}