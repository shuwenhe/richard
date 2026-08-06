#include<bits/stdc++.h>

using namespace std;

char s[20];

int solve(){
	scanf("%s",s + 1);
	int l = strlen(s + 1),ans = 0;
	for(int i = 1;i <= l;i++){
		if(s[i] == 'a'){
			ans++;
		}
	}
	return ans;
}

int main(){
	for(int i = 1;i <= 3;i++){
		printf("%d\n",solve());
	}
}
