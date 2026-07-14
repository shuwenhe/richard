#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[1001];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int t = a[1];
	for(int i = 2;i <= n;i++){
		a[i - 1] = a[i];
	}
	a[n] = t;
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<endl;
	}
}
