#include<bits/stdc++.h>

using namespace std;

int a[2001];
int x,n,d = 1000;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x;
		a[x + d]++;
	}
	for(int i = 1;i <= 2000;i++){
		for(int j = 1;j <= a[i];j++){
			cout<<i - d<<" ";
		}
	}
}
