#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n >= 100){
		if(n % 2 == 0 ){
			cout<<1;
		}else{
			cout<<2;
		}
	}else{
		if(n % 2 == 0){
			cout<<3;
		}else{
			cout<<4;
		}
	}
}
