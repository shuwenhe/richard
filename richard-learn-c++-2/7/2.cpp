#include<bits/stdc++.h>

using namespace std;

int n,q,a[100001],c[100002],s[100001];

int main(){
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= q;i++){
		int l,r;
		cin>>l>>r;
		c[l]++;c[r + 1]--;
	}
	s[0] = 0;
	for(int i = 1;i <= n;i++)
		s[i] = s[i - 1] + c[i];
	for(int i = 1;i <= n;i++)
		cout<<a[i] + s[i]<<" ";
}
