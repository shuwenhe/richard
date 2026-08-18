#include<bits/stdc++.h>

using namespace std;

int w,n,a[30001],c[201];

int main(){
	cin>>w>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		++c[x];
	}
	int l = 0;
	for(int i = 5;i <= w;i++){
		for(int j = 1;j <= c[i];j++){
			a[++l] = i;
		}
	}
	int ans = n;
	int i = 1;
	for(int j = n;j > i;--j){
		if(a[i] + a[j] <= w){
			--ans,++i;
		}
	}
	cout<<ans;
}
