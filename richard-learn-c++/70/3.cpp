#include<bits/stdc++.h>

using namespace std;

int a[4][4][5];

int main(){
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= 3;j++){
			for(int k = 1;k <= 4;k++){
				printf("%d",a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
