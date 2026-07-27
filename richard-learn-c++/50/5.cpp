#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[110];
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	for(int i = len;i >= 1;i--){
		printf("%c\n",s[i]);
	}
}
