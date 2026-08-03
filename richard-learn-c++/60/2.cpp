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
	for(int i = 1;i <= 105;i++){
		c[i] = 0;
	}
	int r = 0;
	for(int i = la;i > 0;i--){
		r = r * 10 + a[i];
		c[i] = r / b;
		r = r % b;
	}
	while(c[lc] == 0 && lc > 1){
		lc--;
	}
	for(int i = lc;i >= 1;i--){
		cout<<c[i];
	}
	cout<<endl;
	cout<<r<<endl;
}
