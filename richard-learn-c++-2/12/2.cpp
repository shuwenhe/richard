#include<bits/stdc++.h>

using namespace std;

int n,s[101][2],top = 0;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		int opt;
		cin>>opt;
		if(opt == 1){
			int x,y;
			cin>>x>>y;
			++top;
			s[top][0] = x;s[top][1] = y;
		}else{
			if(!top){
				cout<<"error"<<endl;
			}else{
				cout<<s[top][0]<<" "<<s[top][1];
				--top;
			}
		}
	}
}
