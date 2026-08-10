#include<bits/stdc++.h>

using namespace std;

int n,m,k,p,q;

char name[15][15][110][15];

int main(){
	cin>>n>>m>>k>>p;
	for(int i = 1;i <= p;i++){
		int g,c,num;
		cin>>g>>c>>num;
		scanf("%s",name[g][c][num]);
	}
	cin>>q;
	for(int i = 1;i <= q;i++){
		int g,c,num;
		cin>>g>>c>>num;
		if(strlen(name[g][c][num]) == 0){
			cout<<"Error"<<endl;
		}else{
			printf("%s\n",name[g][c][num]);
		}
	}
}
