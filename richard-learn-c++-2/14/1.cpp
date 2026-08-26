#include<bits/stdc++.h>

using namespace std;

int n,a[1001];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++){
		int ans = a[i];
		for(int j = 1;j < i;j++)
			ans += min(a[i],a[j]);
		for(iniit j = i + 1;j <= n;j++){
			ans += min(a[i] - 1,a[j]);
		}
		cout<<ans<<" ";
	}
}
