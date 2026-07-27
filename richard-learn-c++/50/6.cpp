#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[110];
	int l;
	char ch;
	scanf("%s",s + 1);
	l = strlen(s + 1);
	for(int i = 1;i <= l / 2;i++){
		ch = s[i];
		s[i] = s[l - i + 1];
		s[l - i + 1] = ch;
	}
	printf("%s\n",s + 1);
}

