#include<bits/stdc++.h>

using namespace std;

int a[101][101][101],n;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				cin>>a[i][j][k];
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cout<<a[i][j][k]<<" ";
			}
			cout<<endl;
		}
	}
}
