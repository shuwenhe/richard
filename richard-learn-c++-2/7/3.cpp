#include<bits/stdc++.h>

using namespace std;

int n,a[100001];
long long s[100001];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	s[0] = 0;
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	long long ans = -1LL<<60LL;
	long long x = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans,s[i] - x);
		x = min(x,s[i]);
	}
	cout<<ans<<endl;
}
