#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1000001];
	char s[1000001];

	scanf("%s",s + 1);
	int l = strlen(s + 1);
	for(int i = 1;i <= l;i++){
		a[i] = s[i] - '0';
	}
	for(int i = 1;i <= l;i++){
		cout<<a[i];
	}
	cout<<endl;
}
