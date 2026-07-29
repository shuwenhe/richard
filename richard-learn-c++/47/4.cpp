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
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= m - j;k++){
				if(a[i][k] > a[i][k + 1]){
					int t = a[i][k];
					a[i][k] = a[i][k + 1];
					a[i][k + 1] = t;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
