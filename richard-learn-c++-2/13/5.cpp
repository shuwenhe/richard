#include<bits/stdc++.h>

using namespace std;

int n,q[1000001],a[1001],ans[1001],f = 1,r;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	r = n;
	for(int i = 1;i <= n;i++)
		q[i] = i;
	for(int t = 1;r >= f;t++){
		int x = q[f];
		++f;
		--a[x];
		if(!a[x]){
			ans[x] = t;
		}else{
			q[++r] = x;
		}
	}
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<" ";
	}
}
