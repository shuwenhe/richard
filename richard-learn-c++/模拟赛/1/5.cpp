#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[101][101];
	int n,m,cnt = 0;
	scanf("%d%d",&n,&m);
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				a[i][j] = ++cnt;
			}
		}else{
			for(int j = m;j >= 1;j--){
				a[i][j] = ++cnt;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
