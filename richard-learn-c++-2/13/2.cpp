#include<bits/stdc++.h>

using namespace std;

int n,q[101],f= 1,r = 0;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		int opt;
		cin>>opt;
		if(opt == 1){
			char s[21];
			cin>>s;
			q[++r] = s[0];
		}else{
			for(int j = 1;j <= 10 && r >= f;j++){
				printf("%c ",q[f]);
				++f;
			}
			cout<<endl;
		}
	}
}
