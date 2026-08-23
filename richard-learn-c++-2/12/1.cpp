#include<bits/stdc++.h>

using namespace std;

int n,m,s[101][1001],top[101];

int main(){
	cin>>n>>m;
	memset(top,0,sizeof(top));
	for(int i = 1;i <= m;i++){
		int id,opt;
		cin>>id>>opt;
		if(opt == 1){
			int x;
			cin>>x;
			s[id][++top[id]] == x;
		}else{
			if(!top[id]){
				cout<<"error"<<endl;
			}else{
				cout<<s[id][top[id]];
				--top[id];
			}
		}
	}
}
