#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,x1,x2,x3,x4;
	cin>>a>>b;
	for(int i = a;i<=b;i++){
		x1 = i / 1000 % 10;
		x2 = i / 100 % 10
		x3 = i / 10 % 10
		x4 = i % 10;
		if(x1 == 3 || x2 == 3 || x3 == 3 || x4 == 3){
			cout<<i<<endl;
		}
	}
	return 0;
}
