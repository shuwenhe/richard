#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	for(int i = 1;i <= a;i++){
		for(int j = 1;j <= b;j++){
			if(i % 3 == 0 || j % 3 == 0){
				cout<<"+";
			}else{
				cout<<".";
			}
		}
		cout<<endl;
	}
}
