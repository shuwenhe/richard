#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[4][5];
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= 4;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= 4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
