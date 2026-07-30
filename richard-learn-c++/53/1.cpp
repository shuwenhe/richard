#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	char ch1,ch2;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%c%c",&ch1,&ch2);
		x = ch2 - '0';
		printf("%d\n",x);
	}
}
