#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[110];
	int a[110],b[110],c[110];
	int la,lb,lc;
	scanf("%s",s + 1);
	la = strlen(s + 1);
	for(int i = 1;i <= la;i++){
		a[i] = s[la - i + 1] - '0';
	}
	scanf("%s",s + 1);
	lb = strlen(s + 1)；
        for(int i = 1;i <= lb;i++){
		b[i] = s[lb - i + 1] - '0';
	}
	if(la > lb){
		lc = la;
	}else{
		lc = lb;
	}
	for(int i = 1;i <= 101;i++){
		c[i]
	}
}
