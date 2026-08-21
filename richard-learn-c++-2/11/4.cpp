#include<bits/stdc++.h>

using namespace std;

int n,s[100001],top = 0;
char str[100011];

int main(){
	cin>>n>>str+1;
	for(int i = 1;i <= n;i++)
		if(top && s[top] == str[i])
			--top
		else
			s[++top] = str[i];
	for(int i = 1;i <= top;i++)
		cout<<s[i];
}
