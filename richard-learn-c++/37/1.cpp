#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n,k;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		if(k - i >= 1 && k - i <= n && i < k - i){
			 int t = a[i];
			 a[i] = a[k - i];
			 a[k - i] = t;
		}
	}
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
}   
