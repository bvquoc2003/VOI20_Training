#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MaxN=100005;
int n;
vector <int> X, T, x, t, L;
void Nhap() {
	freopen("IVECTOR.INP","r",stdin);
	freopen("IVECTOR.OUT","w",stdout);
	cin>>n;
	T.resize(n+1); X.resize(n+1);
	t.resize(n+1); L.resize(n+1);
	for (int i=1;i<=n;i++) cin>>X[i];
	for (int i=1;i<=n;i++) cin>>T[i];
}
void SolveL() {
	stack <int> S;
	for (int i=1;i<=n;++i) {
		while (!S.empty() && X[S.top()]<X[i]) S.pop();
		L[i]=(S.empty() ? 0 : (S.top()));
		S.push(i);
	}
}
void SortT() {
	vector<ii> tmp;
	for (int i=1;i<=n;i++) tmp.push_back(ii(X[i],t[i]));
	sort(tmp.begin(),tmp.end());
	for (int i=0;i<n;i++) t[i+1]=tmp[i].second;
}
void Process1() {
	SolveL();
	for (int i=1;i<=n;i++) {
		if (L[i]==0) {
			t[i]=0;
			continue;
		}
		t[i]=t[L[i]]+1;
	}
	for (int i=1;i<=n;i++) cout<<L[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<t[i]<<" "; cout<<endl;
	SortT();
	for (int i=1;i<=n;i++) cout<<t[i]<<" "; cout<<endl;
}
void Brute_force1() {
	t[1]=0;
	for (int i=2;i<=n;i++)
	for (int j=1;j<=i;j++) if (X[j]>X[i]) t[i]++;
	SortT();
}
void Xuat() {
	for (int i=1;i<=n;i++) cout<<t[i]<<" "; cout<<endl;
	for (int i=0;i<n;i++) cout<<x[i]<<" "; cout<<endl;
}
int32_t main(void) {
	Nhap();
	// Process1();
	Brute_force1();
	//process 2
	for (int i=n; i>=1; --i) x.insert(x.begin()+T[i],i);
	Xuat();
	return 0;
}