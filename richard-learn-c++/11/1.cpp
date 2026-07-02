#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	if((n >= 100) && (n % 2 == 0)){
		cout<<1;
	}else if((n >= 100) && (n % 2 == 1)){
		cout<<2;
	}else if((n < 100) && (n % 2 == 0)){
		cout<<3;
	}else if((n < 100) && (n % 2 == 1)){
		cout<<4;
	}
}
