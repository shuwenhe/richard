#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[1001];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = n;i >= 1;i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

