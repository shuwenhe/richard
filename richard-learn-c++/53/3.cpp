#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[110];
	char s[110];
	scanf("%s",s + 1);
	int l = strlen(s + 1);
	for(int i = 1;i <= l;i++){
		a[i] = s[l + 1 - i] - '0';
	}
	for(int i = 1;i <= l;i++){
		printf("%d",a[i]);
	}
	cout<<endl;
}
