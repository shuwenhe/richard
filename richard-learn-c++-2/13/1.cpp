#include<bits/stdc++.h>

using namespace std;

int m,q[100001],f = 1,r = 0;

int main(){
	cin>>m;
	for(int i = 1;i <= m;i++){
		char s[11];
		cin>>s;
		if(s[0] == 'q'){
			int k;
			cin>>k;
			cout<<q[f + k - 1];
		}else if(s[1] == 'u'){
			int x;
			cin>>x;
			q[++r] = x;
		}else{
			++f;
		}
	}
}
