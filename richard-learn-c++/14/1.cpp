#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b,c,d;
	a = n / 1000;
	b = n / 100 % 10;
	c = n / 10 % 10;
	d = n % 10;
	if(a == 7){
		cout<<"Yes";
	}else if(b == 7){
		cout<<"Yes";
	}else if(c == 7){
		cout<<"Yes";
	}else if(d == 7){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}
