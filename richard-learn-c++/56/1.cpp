#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[110];
	int a[110],b,c[110];
	int la,lc;
	scanf("%s",s + 1);
	la = strlen(s + 1);
	for(int i = 1;i <= la;i++){
		a[i] = s[la - i + 1] - '0';
	}
	scanf("%d",&b);
	lc = la;
	for(int i = 1;i <= 101;i++){
		c[i] = 0;
	}
	for(int i = 1;i <= lc;i++){
		if(i == 1){
			c[i] = a[i] - b;
		}else{
			c[i] = a[i] + c[i];
		}
		if(c[i] < 0){
			c[i + 1]--;
			c[i] += 10;
		}
	}
	if(c[lc] == 0){
		lc--;
	}
	for(int i = lc;i >= 1;i--){
		printf("%d",c[i]);
	}
}
