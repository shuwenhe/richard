#include<bits/stdc++.h>

using namespace std;

int a[1001][1001];
int n,m;

void ppd(int b[][1001]){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	ppd(a); 
}
