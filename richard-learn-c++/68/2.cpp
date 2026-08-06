#include<bits/stdc++.h>

using namespace std;

char s[20];

int solve(char ss[]){
	int l = strlen(ss + 1);
	int sum = 0;
	for(int i = 1;i <= l;i++){
		if(ss[i] == 'a'){
			sum++;
		}
	}
	return sum;
}

int main(){
	for(int i = 1;i <= 3;i++){
		scanf("%s",s + 1);
		printf("%d\n",solve(s));
	}
}
