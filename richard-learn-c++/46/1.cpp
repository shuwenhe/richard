#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[101][101],n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			a[i][j] = j;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			a[i][j] = j;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
