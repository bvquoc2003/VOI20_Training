#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef vector <int> vi;
typedef vector <vi> vvi;
struct data{
	int val, pw2, pw5;
	data () {val=0; pw2=0; pw5=0;}
	data (int _val, int _pw2, int _pw5) {val=_val; pw2=_pw2; pw5=_pw5;}
};
int n, k;
vector <data> a;
int pt2(int x) {
	int res=0;
	while (x%2==0) res++, x/=2;
	return res;
}
int pt5(int x) {
	int res=0;
	while (x%5==0) res++, x/=5;
	return res;
}
vvi f, f0;
void Nhap() {
	freopen("LASTZERO.INP","r",stdin);
	freopen("LASTZERO.OUT","w",stdout);
	int tmp2=0, tmp5=0;
	cin>>n>>k; a.resize(n);
	for (data &x:a) {
		cin>>x.val;
		x.pw2=pt2(x.val);
		x.pw5=pt5(x.val);
		tmp2=max(tmp2,x.pw2);
		tmp5=max(tmp5,x.pw5);
		cout<<x.val<<" "<<x.pw2<<" "<<x.pw5<<endl;
	}
	f0.resize(n+2,vi(tmp2+tmp5+5,0));
	// f0.resize(n+1,vi(105,0));
}
void QHD() {
	for (int i=1;i<=n;i++) {
		for (int )
		f0=f;
	}
}
int32_t main(void) {
	Nhap();
	QHD();
	return 0;
}