#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001][1001],n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] < a[i - 1][j]){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
