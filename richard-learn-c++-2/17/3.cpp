#include<bits/stdc++.h>

using namespace std;

struct Info{
	int d1,d2;
	bool operator < (const Info &A){
		return d1 < A.d1;
	}
}a[100001];

int n,X1,Y1,X2,Y2,a[100001],r[100001],f[100011];

int main(){
	cin>>X1>>Y1>>X2>>Y2;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin>>x>>y;
		a[i].d1 = (x - X1) * (x - X1) + (y - Y1) * (y - Y1);
		a[i].d2 = (x - X2) * (x - X2) + (y - Y2) * (y - Y2);
	}
	sort(a + 1,a + n + 1);
	f[n + 1] = 0;
	for(int i = n;i;i--){
		f[i] = max(f[i + 1],a[i].d2);
	}
	int ans = 1 << 30;
	for(int i = 0;i <= n;i++)
		ans = min(ans,a[i].d1 + f[i + 1]);
	cout<<endl;
}
