#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001][1001];
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 2;i <= n - 1;i++){
		for(int j = 2;j <= m - 1;j++){
			if(a[i - 1][j] > a[i][j] && a[i + 1][j] > a[i][j] && a[i][j - 1] > a[i][j] && a[i][j + 1] > a[i][j]){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
}
