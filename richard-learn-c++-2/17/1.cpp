#include<bits/stdc++.h>

using namespace std;

struct Info{
	int x,y;
}s[101];
int n,top = 0;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		int opt;
		cin>>opt;
		if(opt == 1){
			int x,y;
			cin>>x>>y;
			++top;
			s[top].x = x;s[top].y = y;
		}else{
			if(!top){
				cout<<"error"<<endl;
			}else{
				cout<<s[top].x,s[top].y;
				--top;
			}
		}
	}
}
