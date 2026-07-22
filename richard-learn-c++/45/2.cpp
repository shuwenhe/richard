#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001][1001],n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i]>>a[j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<a[i]<<""<<a[j]<<" ";
		}
		cout<<endl;
	}
}


