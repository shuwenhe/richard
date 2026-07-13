#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,t;
	cin>>a>>b;
	if(a < b){
	        t = a;
		a = b;
		b = t;
	}
	for(int i = a;i >= b;i--){
		if(i % 3 != 0){
		cout<<i<<endl;
		}
	}
}
