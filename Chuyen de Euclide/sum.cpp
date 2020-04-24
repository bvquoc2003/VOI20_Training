#include <bits/stdc++.h>
using namespace std;
int64_t a, b, f_99999, res;
int Init() {
	for (int i=1;i<=99999;i++) {
		int t=i;
		while (t!=0) {
			f_99999+=t%10;
			t/=10;
		}
	}
}
int64_t f(int64_t x) { //Sum[1,x]
	int64_t res=0;
	int c=x/100000;
	for (int i=1;i<c;i++) {
		int64_t t=i;
		while (t!=0) {
			res+=t%10;
			t/=10;
		}
	}
	res=100000*res+c*f_99999;
	for (int i=x-(x%100000);i<=x;i++) {
		int64_t t=i;
		while (t!=0) {
			res+=t%10;
			t/=10;
		}
	}
	return res;
}
int32_t main(void) {
	freopen("sum.inp","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>a>>b;
	Init();
	res=int64_t(f(b)-f(a-1));
	cout<<res;
	return 0;
}