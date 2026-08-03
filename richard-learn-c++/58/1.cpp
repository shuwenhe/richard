#include<bits/stdc++.h>

using namespace std;

char s[110];
int a[110],c[110];
int b,la,lc;

int main(){
	scanf("%s",s + 1);
	la = strlen(s + 1);
	for(int i = 1;i <= la;i++){
		a[i] = s[la - i + 1] - '0';
	}
	scanf("%d",&b);
	lc = la;
	for(int i = 1;i <= 109;i++){
		c[i] = 0;
	}
	for(int i = 1;i <= lc;i++){
		c[i] = a[i] * b + c[i];
		c[i + 1] = c[i] / 10;
		c[i] = c[i] % 10;
	}
	while(c[lc + 1] > 0){
		lc++;
		c[lc + 1] = c[lc] / 10;
		c[lc] %= 10;
	}
	while(c[lc] == 0 && lc > 1){
		lc--;
	}
	for(int i = lc;i >= 1;i--){
		cout<<c[i];
	}
	cout<<endl;
}
