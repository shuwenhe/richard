#include<bits/stdc++.h>

using namespace std;

char s[21];

int main(){
	scanf("%s",s + 1);
	int n = 13,sum = 0,x = 0;
	for(int i = 1;i < n;i++){
		if(s[i] != '-'){
			int y = s[i] - '0';
			++x;
			sum += x * y;
		}
	}
	sum %= 11;
	char c;
	if(sum == 10){
		c = 'X';
	}else{
		c = sum + '0';
	}
	if(s[n] == c){
		printf("Right\n");
	}else{
		for(int i = 1;i < n;i++){
			cout<<s[i];
		}
		cout<<c<<endl;
	}
}
