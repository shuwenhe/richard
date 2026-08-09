#include<bits/stdc++.h>

using namespace std;

int a[1001],b[1001];
int x,n;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x;
		if(x >= 0){
			a[x]++;
		}else if(x < 0){
			b[-x]++;
		}
	}
	for(int i = 1000;i >= 1;i--){
		for(int j = 1;j <= b[i];j++){
			cout<<'-'<<i<<" ";
		}
	}
	for(int i = 0;i <= 1000;i++){
		for(int j = 1;j <= a[i];j++){
			cout<<i<<" ";
		}
	}
}
