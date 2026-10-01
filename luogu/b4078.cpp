#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[101][21];
	int sum[25] = {0};
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			sum[j] += a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int j = 1;j <= m;j++){
			if(a[i][j] * n >= sum[j]){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
