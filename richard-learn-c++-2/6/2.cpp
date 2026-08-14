#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k,a[1001];
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(a[j] > a[i])
				swap(a[i],a[j]);
	int x = 0;
	for(int i = 1;i <= n;i++){
		x += a[i];
		if(x >= k){
			cout<<i<<endl;
			return 0;
		}
	}
}
