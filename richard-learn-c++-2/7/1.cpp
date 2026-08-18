#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];
long long s[100001];

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	s[0] = 0;
	for(int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= m;i++){
		int l,r;
		cin>>l>>r;
		cout<<s[r] - s[l - 1]<<endl;
	}
}
