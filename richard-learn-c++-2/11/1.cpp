#include<bits/stdc++.h>

using namespace std;

int m,s[100001],top = 0;

int main(){
	cin>>m;
	for(int i = 1;i <= m;i++){
		char t[11];
		cin>>t;
		if(t[0] == 't'){
			cout<<s[top];
		}else if(t[1] == 'u'){
			int x;
			cin>>x;
			s[++top] = x;
		}else{
			top--;
		}
	}
}
