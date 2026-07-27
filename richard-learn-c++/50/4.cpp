#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[110];
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	int sum = 0;
	for(int i = 1;i <= len;i++){
		if(s[i] == 'a'){
			sum++;
		}
	}
	printf("%d",sum);
}
