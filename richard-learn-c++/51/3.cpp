#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

int main(){ 
	int a[101][101];
	for(int i = 1;i <= 30;i++){
		for(int j = 1;j <= 30;j++){
			a[i][j] = cnt++;
		}
	}
	for(int i = 1;i <= 30;i++){
		for(int j = 1;j <= 30;j++){
			printf("%d\t",a[i][j]);
		}
		cout<<endl;
	}
}
