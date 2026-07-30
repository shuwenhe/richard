#include<bits/stdc++.h>

using namespace std;

int main(){
        int a[110],b,c[110];
        char s[110];

        scanf("%s",s + 1);
	scanf("%d",&b);
        int la = strlen(s + 1),lc = la;
        for(int i = 1;i <= la;i++){
                a[i] = s[la - i + 1] - '0';
        }
        for(int i = 1;i <= 101;i++){
		c[i] = 0;
		c[1] = a[1] + b;
	}
	for(int i = 1;i <= lc;i++){			
		c[i + 1] = a[i + 1] + c[i] / 10;
		c[i] = c[i] % 10;
	}
	if(c[lc + 1] > 0){
		lc++;
	}
	for(int i = lc;i >= 1;i--){
		printf("%d",c[i]);
	}

}
