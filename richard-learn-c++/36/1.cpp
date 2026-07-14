#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[1001];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 2;i <= n;i++){
		cout<<a[i]<<endl;
	}
	cout<<a[1]<<endl;
}
